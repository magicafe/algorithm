#include "Edge.h"

Edge::Edge(int n1, int n2, int cost)
{
    N1 = n1;
    N2 = n2;
    Cost = cost;
}

bool operator<(const Edge &l, const Edge &r)
{
    return l.Cost < r.Cost;
}