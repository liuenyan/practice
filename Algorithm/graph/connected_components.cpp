#include "connected_components.h"

ConnectedComponents::ConnectedComponents(const Graph &g)
    : marked_(g.V(), 0), id_(g.V(), 0), count_(0)
{
    for(int i=0; i < g.V(); i++) {
        if (!marked_[i]) {
            dfs(g, i);
            count_++;
        }
    }
}

void ConnectedComponents::dfs(const Graph &g, int v)
{
    marked_[v] = 1;
    id_[v] = count_;

    for(int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            dfs(g, w);
        }
    }
}
