 #include <iostream>
#include <string>

#include "FileManager.h"
#include "FrequencyCounter.h"
#include "HuffmanTree.h"
#include "Compressor.h"
#include "Statistics.h"
#include "Decompressor.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Smart File Compression Tool\n";
    std::cout << " Version 1.0\n";
    std::cout << "=====================================\n\n";

    FileManager fileManager;
    FrequencyCounter frequencyCounter;
    HuffmanTree huffmanTree;
    Compressor compressor;
    Statistics statistics;
    Decompressor decompressor;

    std::string inputFileName;

    std::cout << "Enter input file name: ";
    std::getline(std::cin, inputFileName);

    if (!fileManager.readFile("input/" + inputFileName))
    {
        std::cout << "\nError: Unable to open file.\n";
        return 1;
    }

    std::cout << "\nFile loaded successfully!\n";

    // Display original text
    std::cout << "\nOriginal Text\n";
    std::cout << "=============================\n";
    std::cout << fileManager.getFileData() << "\n";

    // Count frequencies
    frequencyCounter.countFrequency(fileManager.getFileData());

    std::cout << "\nFrequency Table\n";
    std::cout << "=============================\n";
    frequencyCounter.displayFrequency();

    // Build Huffman Tree
    huffmanTree.buildTree(frequencyCounter.getFrequencyMap());

    std::cout << "\nHuffman Tree created successfully!\n";

    // Generate Huffman Codes
    huffmanTree.generateCodes();

    std::cout << "\nHuffman Codes\n";
    std::cout << "=============================\n";
    huffmanTree.displayCodes();

    // Compress
    compressor.compress(
        fileManager.getFileData(),
        huffmanTree.getCodes());

    std::cout << "\nCompressed Data\n";
    std::cout << "=============================\n";
    compressor.displayCompressedData();

    // Statistics
    statistics.calculate(
        static_cast<int>(fileManager.getFileData().size()),
        static_cast<int>(compressor.getCompressedData().size()));

    std::cout << "\nCompression Statistics\n";
    std::cout << "=============================\n";
    statistics.displayStatistics();

    // Decompress
    std::string decompressedText =
        decompressor.decompress(
            compressor.getCompressedData(),
            huffmanTree.getRoot());

    std::cout << "\nDecompressed Text\n";
    std::cout << "=============================\n";
    std::cout << decompressedText << "\n";

    return 0;
}