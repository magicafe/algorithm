#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iostream>
#include <algorithm>
#include "MWis.h"

MWis::MWis(std::string filename)
{
    checkIndexes = std::vector<int>{1,2,3,4,17,117,517,997};
    totalWeight = 0;
    std::ifstream fs(filename);
    fs >> verticesCount;
    long weight;
    while (fs >> weight)
    {
        totalWeight += weight;
        vertices.push_back(weight);
    }

    for (int i = 0; i < verticesCount; ++i)
    {
        weightRecords.push_back(0);
    }
}

void MWis::Run()
{
    weightRecords[verticesCount - 1] = findMWis(verticesCount - 1);
    std::cout << "Max IS: " << weightRecords[verticesCount - 1] << std::endl;
}

long MWis::findMWis(int index)
{
    if (index == 0)
    {
        weightRecords[index] = vertices[index];
        return weightRecords[index];
    }

    long weight1 = 0;
    long weight2 = 0;

    if (index - 1 < 0)
    {
        weight1 = 0;
    }
    else if (weightRecords[index - 1] != 0)
    {
        weight1 = weightRecords[index - 1];
    }
    else
    {
        weightRecords[index - 1] = findMWis(index - 1);
        weight1 = weightRecords[index - 1];
    }

    if (index - 2 < 0)
    {
        weight2 = vertices[index];
    }
    else if (weightRecords[index - 2] != 0)
    {
        weight2 = weightRecords[index - 2] + vertices[index];
    }
    else
    {
        weightRecords[index - 2] = findMWis(index - 2);
        weight2 = weightRecords[index - 2] + vertices[index];
    }

    return weight1 > weight2 ? weight1 : weight2;
}