#include "two_color.h"

TwoColor::TwoColor(const Graph &g)
    : marked_(g.V(), 0), color_(g.V(), 0), two_colorable_(true)
{
    for (int s=0; s<g.V(); s++) {
        if (!marked_[s]) {
            dfs(g, s);
        }
    }
}

void TwoColor::dfs(const Graph &g, int v)
{
    marked_[v] = 1;

    for(int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            color_[w] = !color_[v];
            dfs(g, w);
        } else {
            if (color_[v] == color_[w]) {
                two_colorable_ = false;
            }
        }
    }
}
