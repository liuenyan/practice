#include "kosaraju_scc.h"
#include "depth_first_order.h"
#include <iostream>

using namespace std;

KosarajuSCC::KosarajuSCC(const Digraph& g)
    : count_(0)
    , marked_(g.V(), 0)
    , id_(g.V(), 0)
{
    DepthFirstOrder order(g.Reverse());
    for (int v : order.ReversePostOrder()) {
        if (!marked_[v]) {
            dfs(g, v);
            count_++;
        }
    }
}

void KosarajuSCC::dfs(const Digraph& g, int v)
{
    marked_[v] = 1;
    id_[v] = count_;

    for (int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            dfs(g, w);
        }
    }
}
