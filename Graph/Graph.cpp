#include <list>
#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include "Graph.h"

Graph::Graph(int V)
{
    numVertices = V;
    adjLists = new std::list<int>[V];
}

void Graph::Load(std::string &filename)
{
    std::ifstream fs(filename);
    int max = 0;
    int a, b;
    while(fs >> a >> b)
    {
        if (max < a)
        {
            max = a;
        }

        if (max < b)
        {
            max = b;
        }
        adjLists[a - 1].push_back(b - 1);
    }

    std::cout << "Max: " << max << std::endl;
}

void Graph::AddEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
}

std::list<int> Graph::BFS(int start)
{
    std::list<int> result;

    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = false;
    }

    std::list<int> queue;
    queue.push_back(start);
    visited[start] = true;

    std::list<int>::iterator iter;

    while (!queue.empty())
    {
        int v = queue.front();
        result.push_back(v);
        queue.pop_front();

        for (iter = adjLists[v].begin(); iter != adjLists[v].end(); ++iter)
        {
            if (!visited[*iter])
            {
                queue.push_back(*iter);
                visited[*iter] = true;
            }
        }
    }

    delete[] visited;

    return result;
}

std::list<int> Graph::DFS(int start)
{
    std::list<int> result;

    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = false;
    }

    DFSUtil(start, visited, result);

    return result;
}

void Graph::DFSUtil(int v, bool *visited, std::list<int> &result)
{
    result.push_back(v);
    visited[v] = true;

    for (auto iter = adjLists[v].begin(); iter != adjLists[v].end(); ++iter)
    {
        if (!visited[*iter])
        {
            DFSUtil(*iter, visited, result);
        }
    }
}

Graph *Graph::Reverse()
{
    Graph *rev = new Graph(numVertices);
    
    for (int i = 0; i < numVertices; ++i)
    {
        for (auto iter = adjLists[i].begin(); iter != adjLists[i].end(); ++iter)
        {
            rev->adjLists[*iter].push_back(i);
        }
    }

    return rev;
}

std::list<std::list<int> > Graph::ComputeSCC()
{
    std::list<int> stack;
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = false;
    }

    for (int i = 0; i < numVertices; ++i)
    {
        if (!visited[i])
        {
            FillOrder(i, visited, stack);
        }
    }

    Graph *rev = Reverse();

    for (int i = 0; i < numVertices; ++i)
    {
        visited[i] = false;
    }

    std::list<std::list<int> > result;
    while (!stack.empty())
    {
        int v = stack.back();
        stack.pop_back();

        if (!visited[v])
        {
            std::list<int> scc;
            rev->DFSUtil(v, visited, scc);
            result.push_back(scc);
        }
    }

    result.sort([](const std::list<int> &a, const std::list<int> &b) {
        return a.size() > b.size();
    });

    return result;
}

void Graph::FillOrder(int v, bool *visited, std::list<int> &stack)
{
    visited[v] = true;

    for (auto iter = adjLists[v].begin(); iter != adjLists[v].end(); ++iter)
    {
        if (!visited[*iter])
        {
            FillOrder(*iter, visited, stack);
        }
    }

    stack.push_back(v);
}