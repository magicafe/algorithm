#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Knapsack.h"

Knapsack::Knapsack(std::string filename)
{
    std::ifstream fs(filename);
    fs >> knapsackSize >> itemsCount;
    int value, weight;
    while (fs >> value >> weight)
    {
        values.push_back(value);
        weights.push_back(weight);
    }

    A = std::vector<std::vector<int>>(itemsCount + 1, std::vector<int>(knapsackSize + 1));
    for (int i = 0; i < itemsCount + 1; ++i)
    {
        for (int j = 0; j < knapsackSize + 1; ++j)
        {
            A[i][j] = 0;
        }
    }
}

void Knapsack::Run()
{
    for (int i = 1; i <= itemsCount; ++i)
    {
        for (int j = 0; j <= knapsackSize; ++j)
        {
            if (weights[i - 1] > j)
            {
                A[i][j] = A[i - 1][j];
            }
            else
            {
                int a1 = A[i - 1][j];
                int a2 = values[i - 1] + A[i - 1][j - weights[i - 1]];
                A[i][j] = a1 > a2 ? a1 : a2;
            }
        }
    }

    std::cout << A[itemsCount][knapsackSize] << std::endl;
}