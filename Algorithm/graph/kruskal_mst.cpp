#include "kruskal_mst.h"
#include "union_find.h"
#include "shared_ptr_edge_compare.h"
#include <queue>

using namespace std;

KruskalMST::KruskalMST(const EdgeWeightedGraph& g)
{
    priority_queue<shared_ptr<Edge>, vector<shared_ptr<Edge>>, SharedPtrEdgeCompare> pq(SharedPtrEdgeCompare(true));
    UnionFind uf(g.V());

    for (auto edge : g.Edges()) {
        pq.push(edge);
    }

    while(!pq.empty() && mst_.size() < g.V() - 1) {
        auto edge = pq.top();
        pq.pop();
        int v = edge->Either();
        int w = edge->Other(v);
        if (!uf.Connected(v, w)) {
            uf.Union(v, w);
            mst_.push_back(edge);
        }
    }
}

double KruskalMST::Weight() const
{
    double weight = 0;
    for (auto e : mst_) {
        weight += e->Weight();
    }
    return weight;
}
