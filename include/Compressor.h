#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>
#include <unordered_map>

class Compressor
{
private:
    std::string compressedData;

public:
    Compressor();

    void compress(
        const std::string& text,
        const std::unordered_map<char, std::string>& codes
    );

    void displayCompressedData() const;

    std::string getCompressedData() const;
};

#endif