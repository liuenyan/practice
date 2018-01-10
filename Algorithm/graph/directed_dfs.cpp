#include "directed_dfs.h"

using namespace std;

DirectedDFS::DirectedDFS(const Digraph &g, int s)
    : marked_(g.V(), 0)
{
    dfs(g, s);
}

DirectedDFS::DirectedDFS(const Digraph &g, const vector<int> &vec)
    : marked_(g.V(), 0)
{
    for (int v : vec) {
        if (!marked_[v]) {
            dfs(g, v);
        }
    }
}

void DirectedDFS::dfs(const Digraph &g, int v)
{
    marked_[v] = 1;
    for (int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            dfs(g, w);
        }
    }
}
