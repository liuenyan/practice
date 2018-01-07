#ifndef BREADTH_FIRST_PATHS_H_INCLUDED
#define BREADTH_FIRST_PATHS_H_INCLUDED

#include "graph.h"
#include <vector>

class BreadthFirstPaths {
    int s_;
    std::vector<int> marked_;
    std::vector<int> edge_to_;

    void bfs(const Graph &g, int v);
public:
    BreadthFirstPaths(const Graph &g, int s);
    bool HasPathTo(int v) const { return marked_[v]; };
    std::vector<int> PathTo(int v) const;
};

#endif
