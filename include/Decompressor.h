#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <string>

#include "HuffmanTree.h"

class Decompressor
{
public:

    std::string decompress(
        const std::string& compressedData,
        Node* root
    );
};

#endif