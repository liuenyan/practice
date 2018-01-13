#ifndef KRUSKAL_MST_H_INCLUDED
#define KRUSKAL_MST_H_INCLUDED

#include "edge_weighted_graph.h"
#include <memory>
#include <vector>

class KruskalMST {
    std::vector<std::shared_ptr<Edge>> mst_;
public:
    KruskalMST(const EdgeWeightedGraph& g);
    const std::vector<std::shared_ptr<Edge>> &Edges() const { return mst_; };
    double Weight() const;
};

#endif
