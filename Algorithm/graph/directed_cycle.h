#ifndef DIRECTED_CYCLE_H_INCLUED
#define DIRECTED_CYCLE_H_INCLUED

#include "digraph.h"
#include <vector>

// 检测一个有向图是否是有向无环图DAG

class DirectedCycle {
    std::vector<int> marked_;
    std::vector<int> edge_to_;
    std::vector<int> on_stack_;
    std::vector<int>* cycle_;

    void dfs(const Digraph& g, int v);

public:
    DirectedCycle(const Digraph& g);
    ~DirectedCycle();
    bool HasCycle() const;
    const std::vector<int>& Cycle() const;
};

#endif
