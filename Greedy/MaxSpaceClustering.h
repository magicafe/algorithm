#ifndef SPOCK_MAXSPACE_CLUSTERING
#define SPOCK_MAXSPACE_CLUSTERING

#include <vector>
#include <string>
#include "Edge.h"

class MaxSpaceClustering
{
    std::vector<Edge> edges;
    int Count;

  public:
    MaxSpaceClustering(std::string filename);
    int Compute(int maxSpace);
    void PrintInfo();
};

#endif