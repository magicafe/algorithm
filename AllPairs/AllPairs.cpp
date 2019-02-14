#include "AllPairs.h"

#include <string>
#include <fstream>
#include <iostream>

ASAP::AllPairs::AllPairs(std::string filename)
{
    graph = new ASAP::Graph();

    std::ifstream fs(filename);
    fs >> graph->V >> graph->E;
    graph->edges = new ASAP::Edge *[graph->E];
    int u, v, w = 0;
    int idx = 0;
    while (fs >> u >> v >> w)
    {
        graph->edges[idx] = new ASAP::Edge(u - 1, v - 1, w);
        ++idx;
    }
}

ASAP::AllPairs::~AllPairs()
{
    delete graph;
}

void ASAP::AllPairs::Run()
{
    int **dist = new int *[graph->V];
    for (int i = 0; i < graph->V; ++i)
    {
        dist[i] = new int[graph->V];

        if (!BellmanFord(i, dist[i]))
        {
            return;
        }
    }

    int shortest = INT_MAX;
    for (int i = 0; i < graph->V; ++i)
    {
        for (int j = 0; j < graph->V; ++j)
        {
            if (shortest > dist[i][j])
            {
                shortest = dist[i][j];
            }
            // std::cout << dist[i][j] << "\t";
        }
        // std::cout << std::endl;
    }

    std::cout << shortest << std::endl;
}

bool ASAP::AllPairs::BellmanFord(int src, int *dist)
{
    for (int i = 0; i < graph->V; ++i)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i < graph->V - 1; ++i)
    {
        for (int j = 0; j < graph->E; ++j)
        {
            int u = graph->edges[j]->u;
            int v = graph->edges[j]->v;
            int w = graph->edges[j]->w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < graph->E; ++i)
    {
        int u = graph->edges[i]->u;
        int v = graph->edges[i]->v;
        int w = graph->edges[i]->w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            std::cout << "Graph contains negative weight cycle." << std::endl;
            return false;
        }
    }

    return true;
}
