#include "AllPairs.h"

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>

ASAP::AllPairs::AllPairs(std::string filename)
{
    graph = new ASAP::Graph();

    std::ifstream fs(filename);
    fs >> graph->V >> graph->E;
    graph->edges = new ASAP::Edge *[graph->E];
    graph->matrix = new int*[graph->V];
    for (size_t i = 0; i < graph->V; ++i)
    {
        graph->matrix[i] = new int[graph->V];
        for(size_t j = 0; j < graph->V; j++)
        {
            if (i == j)
            {
                graph->matrix[i][j] = 0;
            }
            else
            {
                graph->matrix[i][j] = INT_MAX;
            }
            
        }
        
    }
    int u, v, w = 0;
    int idx = 0;
    while (fs >> u >> v >> w)
    {
        graph->edges[idx] = new ASAP::Edge(u - 1, v - 1, w);
        ++idx;
        graph->matrix[u-1][v-1] = w;
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

        std::cout << i << "\t";
        auto start = std::chrono::system_clock::now();

        if (!BellmanFord(i, dist[i]))
        {
            return;
        }

        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed = end - start;
    
        std::cout << elapsed.count() << std::endl;
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

void ASAP::AllPairs::FloyWarshall()
{
    std::cout << "FloyWarshall" << std::endl;
    int **dist = new int*[graph->V];
    int **pred = new int*[graph->V];

    for (size_t i = 0; i < graph->V; ++i)
    {
        dist[i] = new int[graph->V];
        pred[i] = new int[graph->V];
        for (size_t j = 0; j < graph->V; ++j)
        {
            dist[i][j] = graph->matrix[i][j];
            if (dist[i][j] != 0 && dist[i][j] != INT_MAX)
            {
                pred[i][j] = i;
            }
            else
            {
                pred[i][j] = -1;
            }
            
        }
    }

    std::cout << "Start FloyWarshall Algorithm" << std::endl;

    for (size_t k = 0; k < graph->V; ++k)
    {
        std::cout << k << std::endl;
        for (size_t i = 0; i < graph->V; ++i)
        {
            for(size_t j = 0; j < graph->V; ++j)
            {
                if ((dist[i][k] != INT_MAX) && (dist[k][j] != INT_MAX) && (dist[i][j] > dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    int shortest = INT_MAX;
    for(size_t i = 0; i < graph->V; i++)
    {
        for(size_t j = 0; j < graph->V; j++)
        {
            if (shortest > dist[i][j])
            {
                shortest = dist[i][j];
            }
        }
    }
    std::cout << "Shortest: " << shortest << std::endl;
}

void ASAP::AllPairs::PrintData(int **data)
{
    for(size_t i = 0; i < graph->V; i++)
    {
        for(size_t j = 0; j < graph->V; j++)
        {
            std::cout << std::setw(15) << data[i][j];
        }
        std::cout << std::endl;
    }
    
}