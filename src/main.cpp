 #include <iostream>
#include <string>

#include "FileManager.h"
#include "FrequencyCounter.h"
#include "HuffmanTree.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Smart File Compression Tool\n";
    std::cout << " Version 1.0\n";
    std::cout << "=====================================\n\n";

    FileManager fileManager;
    FrequencyCounter frequencyCounter;
    HuffmanTree huffmanTree;

    std::string fileName;

    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);

    if (fileManager.readFile("input/" + fileName))
    {
        std::cout << "\nFile loaded successfully!\n\n";

        std::cout << "File Contents\n";
        std::cout << "-----------------------------\n";
        std::cout << fileManager.getFileData();

        // Count character frequencies
        frequencyCounter.countFrequency(fileManager.getFileData());

        std::cout << "\n\nFrequency Table\n";
        std::cout << "=========================\n";
        frequencyCounter.displayFrequency();

        // Build Huffman Tree
        huffmanTree.buildTree(
            frequencyCounter.getFrequencyMap()
        );

        std::cout << "\n\nHuffman Tree created successfully!\n";

        // Generate Huffman Codes
        huffmanTree.generateCodes();

        std::cout << "\nHuffman Codes\n";
        std::cout << "=========================\n";
        huffmanTree.displayCodes();

        std::cout << "\n";
    }
    else
    {
        std::cout << "\nFailed to load file.\n";
    }

    return 0;
}