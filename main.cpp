#include <iostream>
#include <string>
#include "Graph/Graph.h"
#include "Utils/Utils.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;

    std::string filename1("../Data/SCCTest1.txt");
    Graph *g1 = new Graph(9);
    g1->Load(filename1);

    // auto result1 = g1->BFS(0);
    // auto result2 = g1->DFS(0);

    // PrintList(result1);
    // PrintList(result2);

    // Graph *g1Rev = g1->Reverse();
    // auto result3 = g1Rev->DFS(2);

    // PrintList(result3);

    auto result1 = g1->ComputeSCC();
    PrintListSize(result1, 5);

    std::string filename2("../Data/SCCTest2.txt");
    Graph *g2 = new Graph(12);
    g2->Load(filename2);

    auto result2 = g2->ComputeSCC();
    PrintListSize(result2, 5); 

    std::string filename3("../Data/SCC.txt");
    Graph *g3 = new Graph(875714);
    g3->Load(filename3);
    auto result3 = g3->ComputeSCC();
    PrintListSize(result3, 5);

    return 0;
}