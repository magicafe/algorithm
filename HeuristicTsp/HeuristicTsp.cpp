#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "HeuristicTsp.h"

HeuristicTsp::HeuristicTsp(std::string filename)
{
    std::ifstream fs(filename);
    fs >> cityCount;
    int i;
    double x, y;
    while(fs >> i >> x >> y){
        cities[i] = {i, x, y};
    }
}

HeuristicTsp::~HeuristicTsp()
{
}

void HeuristicTsp::Run(int S)
{
    
}