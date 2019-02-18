#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <set>
#include <limits>
#include "Tsp.h"

Tsp::Tsp(std::string filename)
{
    std::ifstream fs(filename);
    fs >> cityNum;
    double x, y;
    while (fs >> x >> y)
    {
        cities.push_back({x, y});
    }
    matrix.resize(cityNum);
    for (size_t i = 0; i < cityNum; i++)
    {
        matrix[i].resize(cityNum, 0);
    }

    for (size_t i = 0; i < cityNum; i++)
    {
        for (size_t j = i + 1; j < cityNum; j++)
        {
            double xdis = cities[i].x - cities[j].x;
            double ydis = cities[i].y - cities[j].y;
            double dis = std::sqrt(xdis * xdis + ydis * ydis);
            matrix[i][j] = dis;
            matrix[j][i] = dis;
        }
    }

    for (size_t i = 0; i < cityNum; i++)
    {
        for (size_t j = 0; j < cityNum; j++)
        {
            std::cout << std::setw(8) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

Tsp::~Tsp()
{
}

void Tsp::Run(int S)
{
    std::vector<std::vector<double>> memo;
    std::vector<std::vector<int>> prev;
    memo.resize(cityNum);
    for (size_t i = 0; i < cityNum; i++)
    {
        memo[i].resize(1 << cityNum, MAX_CITY_DIS);
    }
    prev.resize(cityNum);
    for (size_t i = 0; i < cityNum; i++)
    {
        prev[i].resize(1 << cityNum, -1);
    }

    int state = 1 << S;
    double minDis = tsp(S, S, state, memo, prev);

    std::cout << "MinDis: " << minDis << std::endl;

    std::vector<int> tour;
    int index = S;
    while (true)
    {
        tour.push_back(index);
        int nextIndex = prev[index][state];
        if (nextIndex == -1)
        {
            break;
        }
        int nextState = state | (1 << nextIndex);
        state = nextState;
        index = nextIndex;
    }
    tour.push_back(S);

    for (auto &&t : tour)
    {
        std::cout << std::setw(5) << t;
    }
    std::cout << std::endl;
}

std::set<int> Tsp::combinations(int r, int n)
{
    std::set<int> subsets;
    combinations(0, 0, r, n, subsets);
    return subsets;
}

void Tsp::combinations(int set, int at, int r, int n, std::set<int> &subsets)
{
    if (r == 0)
    {
        subsets.insert(set);
    }
    else
    {
        for (int i = at; i < n; i++)
        {
            set = set | (1 << i);
            combinations(set, i + 1, r - 1, n, subsets);
            set = set & (~(1 << i));
        }
    }
}

bool Tsp::notIn(int S, int subset)
{
    return ((1 << S) & subset) == 0;
}

double Tsp::tsp(int S, int i, int state, std::vector<std::vector<double>> &memo, std::vector<std::vector<int>> &prev)
{
    if (state == (1 << cityNum) - 1)
    {
        return matrix[i][S];
    }

    if (memo[i][state] != MAX_CITY_DIS)
    {
        return memo[i][state];
    }

    double minDis = MAX_CITY_DIS;
    int index = -1;
    for (size_t next = 0; next < cityNum; next++)
    {
        if ((state & (1 << next)) != 0)
        {
            continue;
        }

        int nextState = state | (1 << next);
        double newDis = matrix[i][next] + tsp(S, next, nextState, memo, prev);
        if (newDis < minDis)
        {
            minDis = newDis;
            index = next;
        }
    }

    prev[i][state] = index;
    memo[i][state] = minDis;
    return minDis;
}