#include <vector>
#include "Node.h"

namespace hm
{
Node::Node(std::vector<int> &symbols, int weight)
{
    Symbols = symbols;
    Weight = weight;
    Left = nullptr;
    Right = nullptr;
}

int Node::GetMaximumDepth()
{
    int leftDepth = 0;
    int rightDepth = 0;

    if (Left != nullptr)
    {
        leftDepth = Left->GetMaximumDepth();
    }

    if (Right != nullptr)
    {
        rightDepth = Right->GetMaximumDepth();
    }

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int Node::GetMinimumDepth()
{
    int leftDepth = 0;
    int rightDepth = 0;

    if (Left != nullptr)
    {
        leftDepth = Left->GetMinimumDepth();
    }

    if (Right != nullptr)
    {
        rightDepth = Right->GetMinimumDepth();
    }

    return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
}

Node *CombineNode(Node *x, Node *y)
{
    std::vector<int> symbols = std::vector(x->Symbols);
    symbols.insert(symbols.end(), y->Symbols.begin(), y->Symbols.end());
    int weight = x->Weight + y->Weight;
    Node *res = new Node(symbols, weight);
    res->Left = x;
    res->Right = y;

    return res;
}
} // namespace hm