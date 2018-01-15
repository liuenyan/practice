#include "acyclic_sp.h"
#include "topological.h"
#include <stack>

using namespace std;

AcyclicSP::AcyclicSP(const EdgeWeightedDigraph &g, int s)
    : s_(s)
    , dist_to_(g.V(), std::numeric_limits<double>::infinity())
    , edge_to_(g.V(), 0)
{
    dist_to_[s] = 0.0;
    Topological topo = Topological(g);
    for (int v : topo.Order()) {
        relax(g, v);
    }
}

void AcyclicSP::relax(const EdgeWeightedDigraph &g, int v)
{
    for (auto edge : g.GetAdj(v)) {
        int w = edge->To();
        if (dist_to_[v] + edge->Weight() < dist_to_[w]) {
            dist_to_[w] = dist_to_[v] + edge->Weight();
            edge_to_[w] = edge;
        }
    }
}

vector<shared_ptr<DirectedEdge>> AcyclicSP::PathTo(int v) const
{
    stack<shared_ptr<DirectedEdge>> stack;
    vector<shared_ptr<DirectedEdge>> vec;

    for (auto edge = edge_to_[v]; edge != 0; edge = edge_to_[edge->From()]) {
        stack.push(edge);
    }

    while (!stack.empty()) {
        vec.push_back(stack.top());
        stack.pop();
    }
    return vec;
}
