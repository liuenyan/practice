#ifndef DEPTH_FIRST_ORDER_H_INCLUDED
#define DEPTH_FIRST_ORDER_H_INCLUDED

#include "digraph.h"
#include "edge_weighted_digraph.h"
#include <stack>
#include <vector>

class DepthFirstOrder {
    std::vector<int> pre_;
    std::vector<int> post_;
    std::vector<int> reverse_post_;
    std::stack<int> reverse_post_stack_;
    std::vector<int> marked_;

    void dfs(const Digraph& g, int v);
    void dfs(const EdgeWeightedDigraph& g, int v);
    void makeReversePostOrder();

public:
    explicit DepthFirstOrder(const Digraph& g);
    explicit DepthFirstOrder(const EdgeWeightedDigraph& g);
    const std::vector<int>& PreOrder() const { return pre_; };
    const std::vector<int>& PostOrder() const { return post_; };
    const std::vector<int>& ReversePostOrder() const { return reverse_post_; };
};

#endif
