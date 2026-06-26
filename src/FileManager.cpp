#include "FileManager.h"

#include <fstream>
#include <sstream>
#include <iostream>

FileManager::FileManager()
{
    fileName = "";
    fileData = "";
}

bool FileManager::readFile(const std::string& fileName)
{
    this->fileName = fileName;

    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cout << "Error: Could not open file.\n";
        return false;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();

    fileData = buffer.str();

    inputFile.close();

    return true;
}

bool FileManager::writeFile(const std::string& fileName,
                            const std::string& data)
{
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open())
    {
        return false;
    }

    outputFile << data;

    outputFile.close();

    return true;
}

std::string FileManager::getFileData() const
{
    return fileData;
}