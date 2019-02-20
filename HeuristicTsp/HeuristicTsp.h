#ifndef SPOCK_HEURISTIC_TSP
#define SPOCK_HEURISTIC_TSP

#include <map>
#include <vector>
#include <string>

struct HCity
{
    int index;
    double x;
    double y;
};

class HeuristicTsp
{
private:
    int cityCount;
    std::map<int, HCity> cities;

public:
    HeuristicTsp(std::string filename);
    ~HeuristicTsp();
    void Run(int S);
};

#endif