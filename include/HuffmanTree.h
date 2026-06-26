#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

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

};

#endif