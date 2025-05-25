#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <bitset>

class Huffman {
public:
    void compress(const std::string& inputFile, const std::string& outputFile);
    void decompress(const std::string& inputFile, const std::string& outputFile);

private:
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;
        Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    };

    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };

    void buildFrequencyTable(const std::string& inputFile, std::unordered_map<char, int>& freqTable);
    Node* buildHuffmanTree(const std::unordered_map<char, int>& freqTable);
    void buildCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& codes);
    void writeCompressedFile(const std::string& inputFile, const std::string& outputFile, std::unordered_map<char, std::string>& codes);
    void serializeTree(Node* root, std::ofstream& out);
    Node* deserializeTree(std::ifstream& in);
    void decodeFile(std::ifstream& in, std::ofstream& out, Node* root, int paddingBits);
    void freeTree(Node* root);
};

#endif

