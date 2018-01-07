#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int v)
    : V_(v), E_(0), adj_(v, list<int>())
{

}

Graph::Graph(ifstream &ifs)
{
    int E;
    int v, w;
    ifs >> V_ >> E;

    for(int i=0; i < V_; i++) {
        adj_.push_back(list<int>());
    }

    for (int i=0; i<E; i++) {
        ifs >> v >> w;
        AddEdge(v, w);
    }
}

void Graph::AddEdge(int v, int w)
{
    adj_[v].push_back(w);
    adj_[w].push_back(v);
    E_++;
}
