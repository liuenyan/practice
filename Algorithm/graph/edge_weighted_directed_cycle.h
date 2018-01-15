#ifndef EDGE_WEIGHTED_DIRECTED_CYCLE_H_INCLUDED
#define EDGE_WEIGHTED_DIRECTED_CYCLE_H_INCLUDED

#include "edge_weighted_digraph.h"
#include <vector>
#include <memory>

class EdgeWeightedDirectedCycle {
    std::vector<int> marked_;
    std::vector<std::shared_ptr<DirectedEdge>> edge_to_;
    std::vector<int> on_stack_;
    std::vector<std::shared_ptr<DirectedEdge>>* cycle_;

    void dfs(const EdgeWeightedDigraph& g, int v);

public:
    EdgeWeightedDirectedCycle(const EdgeWeightedDigraph &g);
    ~EdgeWeightedDirectedCycle();
    bool HasCycle() const;
    const std::vector<std::shared_ptr<DirectedEdge>> &Cycle() const;
};

#endif
