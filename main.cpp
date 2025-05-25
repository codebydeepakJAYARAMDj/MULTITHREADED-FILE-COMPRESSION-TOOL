#include <iostream>
#include "Huffman.h"

int main() {
    Huffman huff;
    int choice;
    std::string inputFile, outputFile;

    std::cout << "Huffman Compressor/Decompressor\n";
    std::cout << "1. Compress\n";
    std::cout << "2. Decompress\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter input file path: ";
        std::cin >> inputFile;
        std::cout << "Enter output (compressed) file path: ";
        std::cin >> outputFile;
        huff.compress(inputFile, outputFile);
        std::cout << "Compression complete.\n";
    } else if (choice == 2) {
        std::cout << "Enter compressed file path: ";
        std::cin >> inputFile;
        std::cout << "Enter output (decompressed) file path: ";
        std::cin >> outputFile;
        huff.decompress(inputFile, outputFile);
        std::cout << "Decompression complete.\n";
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}

