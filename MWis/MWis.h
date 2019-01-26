#ifndef SPOCK_MWIS
#define SPOCK_MWIS

#include <vector>
#include <string>

class MWis
{
    long verticesCount;
    long totalWeight;
    std::vector<long> vertices;
    std::vector<long> weightRecords;
    std::vector<int> checkIndexes;

public:
    MWis(std::string filename);
    void Run();

protected:
    long findMWis(int index);
};

#endif