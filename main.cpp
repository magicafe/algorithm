#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "Graph/Graph.h"
#include "Utils/Utils.h"
#include "Greedy/MaxSpaceClustering.h"
#include "Greedy/BitClustering.h"
#include "Huffman/Huffman.h"
#include "MWis/MWis.h"
#include "Knapsack/Knapsack.h"
#include "AllPairs.h"
#include "Tsp/Tsp.h"
#include "HeuristicTsp/HeuristicTsp.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;

    // std::string filename1("../Data/SCCTest1.txt");
    // Graph *g1 = new Graph(9);
    // g1->Load(filename1);

    // auto result1 = g1->ComputeSCC();
    // PrintListSize(result1, 5);

    // std::string filename2("../Data/SCCTest2.txt");
    // Graph *g2 = new Graph(12);
    // g2->Load(filename2);

    // auto result2 = g2->ComputeSCC();
    // PrintListSize(result2, 5);

    // std::string filename3("../Data/SCC.txt");
    // Graph *g3 = new Graph(875714);
    // g3->Load(filename3);
    // auto result3 = g3->ComputeSCC();
    // PrintListSize(result3, 5);

    // =========================

    // MaxSpaceClustering clustering("/Users/luodong/workspace/cpp/algorithm/Data/clustering.txt");
    // std::cout << clustering.Compute(4) << std::endl;

    // std::ifstream fs("/Users/luodong/workspace/cpp/algorithm/Data/clustering_big.txt");
    // int verticesNum = 0;
    // int bitSize = 0;
    // fs >> verticesNum >> bitSize;
    // BitClustering bitClustering(fs, verticesNum);
    // bitClustering.Calc1();
    // bitClustering.Calc2();
    // std::cout << bitClustering.Count() << std::endl;

    // hm::Huffman huffman("/Users/luodong/workspace/cpp/algorithm/Data/huffman.txt");
    // huffman.Run();
    // huffman.PrintInfo();

    // MWis mwis("/Users/luodong/workspace/cpp/algorithm/Data/mwis.txt");
    // mwis.Run();

    // Knapsack knapsack("/Users/luodong/workspace/cpp/algorithm/Data/knapsack_big.txt");
    // knapsack.Run();

    // ASAP::AllPairs ap1("/Users/luodong/workspace/cpp/algorithm/Data/g1.txt");
    // ap1.Run();

    // ASAP::AllPairs ap2("/Users/luodong/workspace/cpp/algorithm/Data/g2.txt");
    // ap2.Run();

    // ASAP::AllPairs ap3("/Users/luodong/workspace/cpp/algorithm/Data/g3.txt");
    // ap3.Run();

    // auto start = std::chrono::system_clock::now();
    // ASAP::AllPairs aplarge("/Users/luodong/workspace/cpp/algorithm/Data/large.txt"); // answer:-6 cost time:7284.41s
    // aplarge.FloyWarshall();
    // auto end = std::chrono::system_clock::now();

    // std::chrono::duration<double> elapsed = end - start;

    // std::cout << elapsed.count() << std::endl;

    // auto start = std::chrono::system_clock::now();
    // Tsp tsp("../Data/tsp.txt");
    // tsp.Run(0);
    // auto end = std::chrono::system_clock::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout << elapsed.count() << std::endl;

    auto start = std::chrono::system_clock::now();
    HeuristicTsp tsp("../Data/nn.txt");
    tsp.Run(1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << elapsed.count() << std::endl;

    return 0;
}