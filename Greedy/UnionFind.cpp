#include <array>
#include <iostream>
#include "UnionFind.h"

UnionFind::UnionFind(int n)
{
    tree = std::vector<int>(n, 0);
    size = std::vector<int>(n, 1);

    for (int i = 0; i < n; ++i)
    {
        tree[i] = i;
    }

    count = n;
}

void UnionFind::PrintInfo()
{
    for (int i = 0; i < tree.size(); ++i)
    {
        std::cout << i << ": " << tree[i] << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < size.size(); ++i)
    {
        std::cout << i << ": " << size[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void UnionFind::Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);

    if (xRoot == yRoot)
    {
        return;
    }

    if (size[xRoot] < size[yRoot])
    {
        tree[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
    }
    else
    {
        tree[yRoot] = xRoot;
        size[xRoot] += size[yRoot];
    }

    --count;
}

int UnionFind::Find(int x)
{
    int f = tree[x];
    if (f != x)
    {
        x = Find(f);
    }
    return x;
}

int UnionFind::Count()
{
    return count;
}