#include "edge_weighted_digraph.h"

using namespace std;

EdgeWeightedDigraph::EdgeWeightedDigraph(int v)
    : V_(v)
    , E_(0)
    , adj_(v, list<shared_ptr<DirectedEdge>>())
{
}

EdgeWeightedDigraph::EdgeWeightedDigraph(ifstream &ifs)
    : V_(0)
    , E_(0)
{
    int E;
    ifs >> V_ >> E;

    for (int i=0; i<V_; i++) {
        adj_.push_back(list<shared_ptr<DirectedEdge>>());
    }

    for (int i=0; i<E; i++) {
        int v, w;
        double weight;
        ifs >> v >> w >> weight;
        AddEdge(make_shared<DirectedEdge>(DirectedEdge(v, w, weight)));
    }
}

void EdgeWeightedDigraph::AddEdge(std::shared_ptr<DirectedEdge> edge)
{
    adj_[edge->From()].push_back(edge);
    E_++;
}

vector<shared_ptr<DirectedEdge>> EdgeWeightedDigraph::Edges() const
{
    vector<shared_ptr<DirectedEdge>> edges;
    for (int v = 0; v < V_; v++) {
        for (auto edge : adj_[v]) {
            edges.push_back(edge);
        }
    }
    return edges;
}
