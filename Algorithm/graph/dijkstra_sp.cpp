#include "dijkstra_sp.h"
#include <stack>

using namespace std;

DijkstraSP::DijkstraSP(const EdgeWeightedDigraph& g, int s)
    : s_(s)
    , dist_to_(g.V(), std::numeric_limits<double>::infinity())
    , edge_to_(g.V(), 0)
    , pq_(g.V())
{
    dist_to_[s] = 0.0;
    pq_.Insert(s, make_shared<double>(0.0));

    while (!pq_.Empty()) {
        relax(g, pq_.DelMin());
    }
}

void DijkstraSP::relax(const EdgeWeightedDigraph& g, int v)
{
    for (auto edge : g.GetAdj(v)) {
        int w = edge->To();
        if (dist_to_[v] + edge->Weight() < dist_to_[w]) {
            dist_to_[w] = dist_to_[v] + edge->Weight();
            edge_to_[w] = edge;
            if (pq_.Contains(w)) {
                pq_.Change(w, make_shared<double>(dist_to_[w]));
            } else {
                pq_.Insert(w, make_shared<double>(dist_to_[w]));
            }
        }
    }
}

vector<shared_ptr<DirectedEdge>> DijkstraSP::PathTo(int v) const
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
