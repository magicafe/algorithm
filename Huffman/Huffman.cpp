#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Huffman.h"
#include "Node.h"

namespace hm
{
Huffman::Huffman(std::string filename)
{
    std::ifstream fs(filename);
    int count = 0;
    int weight = 0;
    fs >> count;
    int symbol = 0;
    while (fs >> weight)
    {
        std::vector<int> symbols{symbol};
        nodes.push_back(new Node(symbols, weight));
        ++symbol;
    }

    std::make_heap(nodes.begin(), nodes.end(), NodeCompare());
}

void Huffman::Run()
{
    while (nodes.size() >= 2)
    {
        Node *n1 = nodes.front();
        std::pop_heap(nodes.begin(), nodes.end(), NodeCompare());
        nodes.pop_back();

        Node *n2 = nodes.front();
        std::pop_heap(nodes.begin(), nodes.end(), NodeCompare());
        nodes.pop_back();

        Node *nr = CombineNode(n2, n1);
        nodes.push_back(nr);
        std::push_heap(nodes.begin(), nodes.end(), NodeCompare());
    }
}

void Huffman::PrintInfo()
{
    if (!nodes.empty())
    {
        Node *node = nodes.at(0);

        std::cout << "Minimum Length: " << node->GetMinimumDepth() - 1 << std::endl;

        std::cout << "Maximum Length: " << node->GetMaximumDepth() - 1 << std::endl;
    }
}
} // namespace hm