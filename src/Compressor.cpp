#include "Compressor.h"

#include <iostream>

Compressor::Compressor()
{
    compressedData = "";
}

void Compressor::compress(
    const std::string& text,
    const std::unordered_map<char, std::string>& codes)
{
    compressedData.clear();

    for (char character : text)
    {
        compressedData += codes.at(character);
    }
}

void Compressor::displayCompressedData() const
{
    std::cout << "\nCompressed Data\n";
    std::cout << "=========================\n";
    std::cout << compressedData << "\n";
}

std::string Compressor::getCompressedData() const
{
    return compressedData;
}