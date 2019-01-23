#ifndef SPOCK_UNIONFIND
#define SPOCK_UNIONFIND

#include <vector>

class UnionFind
{
    std::vector<int> tree;
    std::vector<int> size;
    int count;

  public:
    UnionFind(int n);
    void Union(int x, int y);
    int Find(int x);
    int Count();
    void PrintInfo();
};

#endif