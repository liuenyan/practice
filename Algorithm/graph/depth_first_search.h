#ifndef DEPTH_FIRST_SEARCH_H_INCLUDED
#define DEPTH_FIRST_SEARCH_H_INCLUDED

#include "graph.h"

class DepthFirstSearch {
    int count_;
    std::vector<int> marked_;
    void dfs(const Graph &g, int v);
public:
    DepthFirstSearch(const Graph &g, int s);
    ~DepthFirstSearch();
    bool Marked(int v) const { return marked_[v]; };
    int Count() const { return count_; };
};

#endif
