#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "MaxSpaceClustering.h"
#include "UnionFind.h"

MaxSpaceClustering::MaxSpaceClustering(std::string filename)
{
    std::ifstream fs(filename);
    fs >> Count;

    int n1, n2, len = 0;
    while (fs >> n1 >> n2 >> len)
    {
        edges.push_back(Edge(n1 - 1, n2 - 1, len));
    }

    std::sort(edges.begin(), edges.end());
}

int MaxSpaceClustering::Compute(int clusterCount)
{
    int n = Count;
    int res = 9999999;

    UnionFind uf(n);

    for (const Edge &e : edges)
    {
        if (n == clusterCount)
        {
            if (uf.Find(e.N1) != uf.Find(e.N2))
            {
                if (e.Cost < res)
                {
                    res = e.Cost;
                }
            }
        }
        else
        {
            int op1 = uf.Find(e.N1);
            int op2 = uf.Find(e.N2);
            uf.Union(e.N1, e.N2);
            int np1 = uf.Find(e.N1);
            int np2 = uf.Find(e.N2);
            if (op1 != np1 || op2 != np2)
            {
                --n;
            }
        }
    }

    return res;
}

void MaxSpaceClustering::PrintInfo()
{
    std::cout << edges.size() << ", " << edges[0].Cost << " " << edges[0].N1 << " " << edges[0].N2 << std::endl;
}