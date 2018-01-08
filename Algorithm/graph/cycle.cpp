#include "cycle.h"

Cycle::Cycle(const Graph &g)
    : marked_(g.V(), 0), has_cycle_(false)
{
    for(int s=0; s<g.V(); s++) {
        if (!marked_[s]) {
            dfs(g, s, s);
        }
    }
}

void Cycle::dfs(const Graph &g, int v, int u)
{
    marked_[v] = 1;
    for (int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            dfs(g, w, v);
        } else {
            if (w == u) {
                has_cycle_ = true;
            }
        }
    }
}
