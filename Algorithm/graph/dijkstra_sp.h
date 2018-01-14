#ifndef DIJKSTRA_SP_H_INCLUEDED
#define DIJKSTRA_SP_H_INCLUEDED

#include "edge_weighted_digraph.h"
#include "index_min_pq.h"
#include <limits>
#include <memory>
#include <vector>

class DijkstraSP {
    int s_;
    std::vector<double> dist_to_;
    std::vector<std::shared_ptr<DirectedEdge>> edge_to_;
    IndexMinPQ<double> pq_;

    // 放松操作
    void relax(const EdgeWeightedDigraph& g, int v);

public:
    DijkstraSP(const EdgeWeightedDigraph& g, int s);
    double DistTo(int v) const { return dist_to_[v]; };
    bool HasPathTo(int v) const { return dist_to_[v] < std::numeric_limits<double>::infinity(); };
    std::vector<std::shared_ptr<DirectedEdge>> PathTo(int v) const;
};

#endif
