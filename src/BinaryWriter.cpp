 #include "BinaryWriter.h"

#include <fstream>

bool BinaryWriter::writeToFile(
    const std::string& fileName,
    const std::string& compressedData)
{
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open())
    {
        return false;
    }

    outputFile << compressedData;

    outputFile.close();

    return true;
}