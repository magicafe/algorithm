#ifndef SPOCK_GRAPH
#define SPOCK_GRAPH

#include <string>
#include <list>

class Graph
{
    int numVertices;
    std::list<int> *adjLists;

public:
    Graph(int V);
    void Load(std::string &filename);
    void AddEdge(int src, int dest);
    std::list<int> BFS(int start);
    std::list<int> DFS(int start);
    Graph *Reverse();
    std::list<std::list<int> > ComputeSCC();

protected:
    void DFSUtil(int v, bool *visited, std::list<int> &result);
    void FillOrder(int v, bool *visited, std::list<int> &stack);
};

#endif