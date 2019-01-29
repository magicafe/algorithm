#include <iostream>
#include <string>
#include <fstream>
#include "Graph/Graph.h"
#include "Utils/Utils.h"
#include "Greedy/MaxSpaceClustering.h"
#include "Greedy/BitClustering.h"
#include "Huffman/Huffman.h"
#include "MWis/MWis.h"
#include "Knapsack/Knapsack.h"

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

    Knapsack knapsack("/Users/luodong/workspace/cpp/algorithm/Data/knapsack_big.txt");
    knapsack.Run();

    return 0;
}