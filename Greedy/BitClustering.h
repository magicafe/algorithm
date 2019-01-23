#ifndef SPOCK_BITCLUSTERING
#define SPOCK_BITCLUSTERING

#include <string>
#include <bitset>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "UnionFind.h"

class BitClustering
{
    std::unordered_map<std::bitset<24>, int> vertices;
    UnionFind *uf;

  public:
    BitClustering(std::ifstream &fs, int n);
    ~BitClustering();
    void Calc1();
    void Calc2();
    int Count();
};

BitClustering::BitClustering(std::ifstream &fs, int n)
{
    vertices = std::unordered_map<std::bitset<24>, int>();
    uf = new UnionFind(n);

    std::bitset<24> bitSet;
    int bitIndex = 24;
    int index = -1;
    int bit;
    while (fs >> bit)
    {
        if (bitIndex == 24)
        {
            if (index > -1)
            {
                if (vertices.find(bitSet) != vertices.end())
                {
                    uf->Union(index, vertices[bitSet]);
                }
                else
                {
                    vertices[bitSet] = index;
                }
            }

            bitIndex = 0;
            bitSet = std::bitset<24>();

            ++index;
        }

        if (bit == 1)
        {
            bitSet.set(bitIndex);
        }

        ++bitIndex;
    }

    // The last line
    if (vertices.find(bitSet) != vertices.end())
    {
        uf->Union(index, vertices[bitSet]);
    }
    else
    {
        vertices[bitSet] = index;
    }

    // uf->PrintInfo();

    // std::cout << "Count: " << vertices.size() << std::endl;

    // for (auto &&v : vertices)
    // {
    //     std::cout << v.first << std::endl;
    // }
}

BitClustering::~BitClustering()
{
    delete uf;
}

void BitClustering::Calc1()
{
    for (auto &&v : vertices)
    {
        for (int i = 0; i < 24; ++i)
        {
            std::bitset<24> temp = std::bitset<24>(v.first);
            temp.flip(i);
            if (vertices.find(temp) != vertices.end())
            {
                uf->Union(v.second, vertices[temp]);
            }
        }
    }

    // uf->PrintInfo();
}

void BitClustering::Calc2()
{
    for (auto &&v : vertices)
    {
        for (int i = 0; i < 24; ++i)
        {
            for (int j = 0; j < 24; ++j)
            {
                std::bitset<24> temp = std::bitset<24>(v.first);
                temp.flip(i);
                temp.flip(j);
                if (vertices.find(temp) != vertices.end())
                {
                    uf->Union(v.second, vertices[temp]);
                }
            }
        }
    }

    // uf->PrintInfo();
}

int BitClustering::Count()
{
    return uf->Count();
}

#endif