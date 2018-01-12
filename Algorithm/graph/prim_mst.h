#ifndef PRIM_MST_H_INCLUED
#define PRIM_MST_H_INCLUED

#include "edge_weighted_graph.h"
#include "index_min_pq.h"

class PrimMST {
    std::vector<std::shared_ptr<Edge>> edge_to_;
    std::vector<double> dist_to_;
    std::vector<int> marked_;
    IndexMinPQ<double> pq_;
    std::vector<std::shared_ptr<Edge>> mst_;

    void visit(const EdgeWeightedGraph& g, int v);

public:
    PrimMST(const EdgeWeightedGraph& g);
    const std::vector<std::shared_ptr<Edge>>& Edges() const;
    double Weight() const;
};

#endif
