#ifndef TOPOLOGICAL_H_INCLUED
#define TOPOLOGICAL_H_INCLUED

#include "digraph.h"
#include "edge_weighted_digraph.h"
#include <vector>

class Topological {
    std::vector<int> *order_;
public:
    explicit Topological(const Digraph &g);
    explicit Topological(const EdgeWeightedDigraph &g);
    ~Topological();
    bool IsDAG() const { return order_ != nullptr; };
    std::vector<int> &Order() const { return *order_; };
};

#endif
