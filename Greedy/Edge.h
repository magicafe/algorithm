#ifndef SPOCK_EDGE
#define SPOCK_EDGE

class Edge
{
  public:
    int Cost;
    int N1;
    int N2;

  public:
    Edge(int n1, int n2, int cost);
    friend bool operator<(const Edge &l, const Edge &r);
};

#endif