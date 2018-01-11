#include "lazy_prim_mst.h"

using namespace std;

LazyPrimMST::LazyPrimMST(const EdgeWeightedGraph& g)
    : marked_(g.V(), 0)
    , cmp_(true)
    , pq_(cmp_)
{
    // 假设图是连通的
    visit(g, 0);
    while (!pq_.empty()) {
        // 取出权重最小的边
        auto e = pq_.top();
        pq_.pop();
        int v = e->Either();
        int w = e->Other(v);
        if (marked_[v] && marked_[w]) {
            // 跳过失效的边
            continue;
        }
        //找到一条横切边
        mst_.push_back(e);

        if (!marked_[v]) {
            visit(g, v);
        }
        if (!marked_[w]) {
            visit(g, w);
        }
    }
}

void LazyPrimMST::visit(const EdgeWeightedGraph& g, int v)
{
    marked_[v] = 1;
    for (auto e : g.GetAdj(v)) {
        int w = e->Other(v);
        if (!marked_[w]) {
            pq_.push(e);
        }
    }
}

const vector<shared_ptr<Edge>>& LazyPrimMST::Edges() const
{
    return mst_;
}

double LazyPrimMST::Weight() const
{
    double weight;
    for (auto e : mst_) {
        weight += e->Weight();
    }
    return weight;
}
