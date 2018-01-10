#include "digraph.h"
#include <iostream>
using namespace std;

Digraph::Digraph(int v)
    : V_(v)
    , E_(0)
    , adj_(v, list<int>())
{
}

Digraph::Digraph(ifstream &ifs)
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

void Digraph::AddEdge(int v, int w)
{
    adj_[v].push_back(w);
    E_++;
}

Digraph Digraph::Reverse() const
{
    Digraph g(V_);
    for (int v = 0; v < V_; v++) {
        for (int w : adj_[v]) {
            g.AddEdge(w, v);
        }
    }
    return g;
}
