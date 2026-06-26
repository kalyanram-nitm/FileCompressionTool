#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <unordered_map>
#include <string>

struct Node
{
    char character;
    int frequency;

    Node* left;
    Node* right;

    Node(char ch, int freq)
    {
        character = ch;
        frequency = freq;

        left = nullptr;
        right = nullptr;
    }
};

class HuffmanTree
{
private:
    Node* root;

    std::unordered_map<char, std::string> huffmanCodes;

    void generateCodesHelper(
        Node* node,
        const std::string& code
    );

public:
    HuffmanTree();

    void buildTree(
        const std::unordered_map<char, int>& frequencyMap
    );

    Node* getRoot() const;

    void generateCodes();

    void displayCodes() const;

    const std::unordered_map<char, std::string>&
    getCodes() const;

    ~HuffmanTree();
};

#endif