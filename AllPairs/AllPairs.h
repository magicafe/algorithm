#ifndef SPOCK_ASAP
#define SPOCK_ASAP

#include <string>
#include <vector>

namespace ASAP
{
class Edge
{
public:
  int u;
  int v;
  int w;

  Edge(int _u, int _v, int _w)
  {
    u = _u;
    v = _v;
    w = _w;
  };
};

class Graph
{
public:
  int V;
  int E;
  ASAP::Edge **edges;

  ~Graph()
  {
    if (edges != nullptr)
    {
      for (size_t i = 0; i < E; i++)
      {
        delete edges[i];
      }
      delete[] edges;
    }
  }
};

class AllPairs
{
private:
  ASAP::Graph *graph;

public:
  AllPairs(std::string filename);
  ~AllPairs();
  bool BellmanFord(int src, int *dist);
  void Run();
};
} // namespace ASAP

#endif