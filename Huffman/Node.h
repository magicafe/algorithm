#ifndef SPOCK_HUFFMAN_NODE
#define SPOCK_HUFFMAN_NODE

#include <vector>

namespace hm
{
class Node
{
  public:
    std::vector<int> Symbols;
    int Weight;

    Node *Left;
    Node *Right;

    Node(std::vector<int> &symbols, int weight);
    int GetMaximumDepth();
    int GetMinimumDepth();

    friend Node *CombineNode(Node *x, Node *y);
};

struct NodeCompare
{
    bool operator()(const Node *x, const Node *y)
    {
        return x->Weight > y->Weight;
    }
};

} // namespace hm

#endif