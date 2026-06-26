#include "Decompressor.h"

std::string Decompressor::decompress(
    const std::string& compressedData,
    Node* root)
{
    std::string originalText;

    Node* current = root;

    for (char bit : compressedData)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current->left == nullptr &&
            current->right == nullptr)
        {
            originalText += current->character;

            current = root;
        }
    }

    return originalText;
}