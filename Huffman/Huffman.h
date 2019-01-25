#ifndef SPOCK_HUFFMAN
#define SPOCK_HUFFMAN

#include <string>
#include <vector>
#include <algorithm>
#include "Node.h"

namespace hm
{
class Huffman
{
    std::vector<Node *> nodes;

  public:
    Huffman(std::string filename);
    void Run();
    void PrintInfo();
};
} // namespace hm

#endif