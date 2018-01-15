#ifndef ACYCLIC_SP_H_INCLUDED
#define ACYCLIC_SP_H_INCLUDED

#include "edge_weighted_digraph.h"
#include "index_min_pq.h"
#include <vector>
#include <limits>

class AcyclicSP {
    int s_;
    std::vector<double> dist_to_;
    std::vector<std::shared_ptr<DirectedEdge>> edge_to_;

    void relax(const EdgeWeightedDigraph &g, int v);

public:
    AcyclicSP(const EdgeWeightedDigraph &g, int s);
    double DistTo(int v) const { return dist_to_[v]; };
    bool HasPathTo(int v) const { return dist_to_[v] != std::numeric_limits<double>::infinity();};
    std::vector<std::shared_ptr<DirectedEdge>> PathTo(int v) const;
};

#endif
