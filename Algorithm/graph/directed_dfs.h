#ifndef DIRECTED_DFS_H_INCLUDED
#define DIRECTED_DFS_H_INCLUDED

#include "digraph.h"
#include <vector>

class DirectedDFS {
    std::vector<int> marked_;

    void dfs(const Digraph &g, int v);

public:
    DirectedDFS(const Digraph& g, int s);
    DirectedDFS(const Digraph& g, const std::vector<int>& vec);
    bool marked(int v) const { return marked_[v]; };
};

#endif
