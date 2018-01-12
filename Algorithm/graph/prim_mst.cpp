#include "prim_mst.h"
#include <limits>

using namespace std;

PrimMST::PrimMST(const EdgeWeightedGraph& g)
    : edge_to_(g.V(), 0)
    , dist_to_(g.V(), std::numeric_limits<double>::infinity())
    , marked_(g.V(), 0)
    , pq_(g.V())
{
    dist_to_[0] = 0.0;
    pq_.Insert(0, make_shared<double>(0.0));
    visit(g, 0);

    while (!pq_.Empty()) {
        visit(g, pq_.DelMin());
    }

    for (int v =1; v < g.V(); v++) {
        mst_.push_back(edge_to_[v]);
    }
}

void PrimMST::visit(const EdgeWeightedGraph& g, int v)
{
    marked_[v] = 1;

    for (auto edge : g.GetAdj(v)) {
        int w = edge->Other(v);
        if (marked_[w]) {
            continue;
        }

        if (edge->Weight() < dist_to_[w]) {
            edge_to_[w] = edge;
            dist_to_[w] = edge->Weight();
            if (pq_.Contains(w)) {
                pq_.Change(w, make_shared<double>(edge->Weight()));
            } else {
                pq_.Insert(w, make_shared<double>(edge->Weight()));
            }
        }
    }
}

const vector<shared_ptr<Edge>> &PrimMST::Edges() const
{
    return mst_;
}

double PrimMST::Weight() const
{
    double weight = 0;
    for (auto e : mst_) {
        weight += e->Weight();
    }
    return weight;
}
