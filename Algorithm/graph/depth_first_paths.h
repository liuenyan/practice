#ifndef DEPTH_FIRST_PATHS_H_INCLUDED
#define DEPTH_FIRST_PATHS_H_INCLUDED

#include "Graph.h"
#include <vector>

class DepthFirstPaths {
private:
    int s_;
    std::vector<int> marked_;
    std::vector<int> edge_to_;

    void dfs(const Graph &g, int v);
public:
    DepthFirstPaths(const Graph &g, int s);
    bool HasPathTo(int v) const { return marked_[v]; };
    std::vector<int> PathTo(int v) const;
};

#endif
