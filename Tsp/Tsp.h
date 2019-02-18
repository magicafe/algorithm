#ifndef SPOCK_TSP
#define SPOCK_TSP

#include <vector>
#include <string>
#include <set>

#define MAX_CITY_DIS 100000000

struct City
{
    double x;
    double y;
};

class Tsp
{
  private:
    int cityNum;
    std::vector<City> cities;
    std::vector<std::vector<double>> matrix;

  public:
    Tsp(std::string filename);
    ~Tsp();
    void Run(int S);

  public:
    std::set<int> combinations(int r, int n);
    void combinations(int set, int at, int r, int n, std::set<int> &subsets);
    bool notIn(int S, int subset);

  protected:
    double tsp(int S, int i, int state, std::vector<std::vector<double>> &memo, std::vector<std::vector<int>> &prev);
};

#endif