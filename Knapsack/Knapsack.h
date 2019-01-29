#ifndef SPOCK_KNAPSACK
#define SPOCK_KNAPSACK

#include <string>
#include <vector>

class Knapsack
{
    int knapsackSize;
    int itemsCount;
    std::vector<int> values;
    std::vector<int> weights;
    std::vector<std::vector<int>> A;

  public:
    Knapsack(std::string filename);
    void Run();
};

#endif