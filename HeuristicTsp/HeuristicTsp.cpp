#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include "HeuristicTsp.h"

HeuristicTsp::HeuristicTsp(std::string filename)
{
    std::ifstream fs(filename);
    fs >> cityCount;
    int i;
    double x, y;
    while (fs >> i >> x >> y)
    {
        cities[i] = {i, x, y};
    }
}

HeuristicTsp::~HeuristicTsp()
{
}

void HeuristicTsp::Run(int S)
{
    double distance = 0;
    HCity sc = cities[S];
    cities.erase(S);

    HCity cur = sc;

    while (!cities.empty())
    {
        double minDisSquare = std::numeric_limits<double>::max();
        int index = -1;
        for (auto &&city : cities)
        {
            double xdis = city.second.x - cur.x;
            double ydis = city.second.y - cur.y;
            double disSquare = xdis * xdis + ydis * ydis;
            if (minDisSquare > disSquare)
            {
                minDisSquare = disSquare;
                index = city.first;
            }
            else if (minDisSquare == disSquare)
            {
                if (index > city.first)
                {
                    index = city.first;
                }
            }
        }

        if (index != -1)
        {
            cur = cities[index];
            cities.erase(index);
            distance += std::sqrt(minDisSquare);
        }
    }

    double xdis = cur.x - sc.x;
    double ydis = cur.y - sc.y;
    distance += std::sqrt(xdis * xdis + ydis * ydis);

    std::cout << std::setprecision(15) << distance << std::endl;
    std::cout << std::setprecision(15) << floor(distance) << std::endl;
}