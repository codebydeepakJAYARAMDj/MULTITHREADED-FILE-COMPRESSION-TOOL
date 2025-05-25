#include "Huffman.h"

void Huffman::compress(const std::string& inputFile, const std::string& outputFile) {
    std::unordered_map<char, int> freqTable;
    buildFrequencyTable(inputFile, freqTable);

    Node* root = buildHuffmanTree(freqTable);

    std::unordered_map<char, std::string> codes;
    buildCodes(root, "", codes);

    std::ofstream out(outputFile, std::ios::binary);
    serializeTree(root, out);
    writeCompressedFile(inputFile, outputFile, codes);

    freeTree(root);
}

void Huffman::decompress(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile, std::ios::binary);
    Node* root = deserializeTree(in);

    int paddingBits = in.get();  // read padding bits
    std::ofstream out(outputFile, std::ios::binary);
    decodeFile(in, out, root, paddingBits);

    freeTree(root);
}

void Huffman::buildFrequencyTable(const std::string& inputFile, std::unordered_map<char, int>& freqTable) {
    std::ifstream in(inputFile, std::ios::binary);
    char ch;
    while (in.get(ch)) {
        freqTable[ch]++;
    }
}

Huffman::Node* Huffman::buildHuffmanTree(const std::unordered_map<char, int>& freqTable) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (auto& pair : freqTable) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}

void Huffman::buildCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = str;
    }
    buildCodes(root->left, str + "0", codes);
    buildCodes(root->right, str + "1", codes);
}

void Huffman::writeCompressedFile(const std::string& inputFile, const std::string& outputFile, std::unordered_map<char, std::string>& codes) {
    std::ifstream in(inputFile, std::ios::binary);
    std::ofstream out(outputFile, std::ios::binary | std::ios::app);

    std::string encodedString = "";
    char ch;
    while (in.get(ch)) {
        encodedString += codes[ch];
    }

    int padding = 8 - (encodedString.size() % 8);
    if (padding != 8) {
        encodedString.append(padding, '0');
    }

    out.put(padding);  // save padding at the start

    for (size_t i = 0; i < encodedString.size(); i += 8) {
        std::bitset<8> bits(encodedString.substr(i, 8));
        out.put(static_cast<char>(bits.to_ulong()));
    }
}

void Huffman::serializeTree(Node* root, std::ofstream& out) {
    if (!root) {
        out.put('#');
        return;
    }

    if (!root->left && !root->right) {
        out.put('L');
        out.put(root->ch);
    } else {
        out.put('I');
    }

    serializeTree(root->left, out);
    serializeTree(root->right, out);
}

Huffman::Node* Huffman::deserializeTree(std::ifstream& in) {
    char marker = in.get();
    if (marker == '#') return nullptr;

    if (marker == 'L') {
        char ch = in.get();
        return new Node(ch, 0);
    }

    Node* node = new Node('\0', 0);
    node->left = deserializeTree(in);
    node->right = deserializeTree(in);
    return node;
}

void Huffman::decodeFile(std::ifstream& in, std::ofstream& out, Node* root, int paddingBits) {
    std::string bitString;
    char byte;
    while (in.get(byte)) {
        bitString += std::bitset<8>(static_cast<unsigned char>(byte)).to_string();
    }

    if (paddingBits > 0)
        bitString.erase(bitString.size() - paddingBits);

    Node* curr = root;
    for (char bit : bitString) {
        curr = (bit == '0') ? curr->left : curr->right;
        if (!curr->left && !curr->right) {
            out.put(curr->ch);
            curr = root;
        }
    }
}

void Huffman::freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

