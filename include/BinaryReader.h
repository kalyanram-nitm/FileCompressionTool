#ifndef BINARYWRITER_H
#define BINARYWRITER_H

#include <string>

class BinaryWriter
{
public:
    bool writeToFile(
        const std::string& fileName,
        const std::string& compressedData
    );
};

#endif