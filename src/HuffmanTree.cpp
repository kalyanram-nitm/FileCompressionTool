#include "HuffmanTree.h"

#include <iostream>
#include <queue>
#include <vector>

struct Compare
{
    bool operator()(Node* left, Node* right)
    {
        return left->frequency > right->frequency;
    }
};

HuffmanTree::HuffmanTree()
{
    root = nullptr;
}

Node* HuffmanTree::getRoot() const
{
    return root;
}

void HuffmanTree::buildTree(
    const std::unordered_map<char, int>& frequencyMap)
{
    std::priority_queue<
        Node*,
        std::vector<Node*>,
        Compare
    > priorityQueue;

    for (const auto& pair : frequencyMap)
    {
        priorityQueue.push(
            new Node(pair.first, pair.second)
        );
    }

    if (priorityQueue.empty())
    {
        root = nullptr;
        return;
    }

    while (priorityQueue.size() > 1)
    {
        Node* left = priorityQueue.top();
        priorityQueue.pop();

        Node* right = priorityQueue.top();
        priorityQueue.pop();

        Node* parent = new Node(
            '\0',
            left->frequency + right->frequency
        );

        parent->left = left;
        parent->right = right;

        priorityQueue.push(parent);
    }

    root = priorityQueue.top();
}

void HuffmanTree::generateCodesHelper(
    Node* node,
    const std::string& code)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left == nullptr &&
        node->right == nullptr)
    {
        huffmanCodes[node->character] = code;
        return;
    }

    generateCodesHelper(node->left, code + "0");
    generateCodesHelper(node->right, code + "1");
}

void HuffmanTree::generateCodes()
{
    huffmanCodes.clear();

    generateCodesHelper(root, "");
}

void HuffmanTree::displayCodes() const
{
    std::cout << "\nCharacter\tHuffman Code\n";
    std::cout << "--------------------------------\n";

    for (const auto& pair : huffmanCodes)
    {
        if (pair.first == ' ')
            std::cout << "SPACE\t\t";
        else if (pair.first == '\n')
            std::cout << "\\n\t\t";
        else
            std::cout << pair.first << "\t\t";

        std::cout << pair.second << '\n';
    }
}

const std::unordered_map<char, std::string>&
HuffmanTree::getCodes() const
{
    return huffmanCodes;
}

static void deleteTree(Node* node)
{
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

HuffmanTree::~HuffmanTree()
{
    deleteTree(root);
}