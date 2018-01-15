#include "depth_first_order.h"

using namespace std;

DepthFirstOrder::DepthFirstOrder(const Digraph &g)
    : marked_(g.V(), 0)
{
    for (int v = 0; v != g.V(); v++) {
        if (!marked_[v]) {
            dfs(g, v);
        }
    }
    makeReversePostOrder();
}

DepthFirstOrder::DepthFirstOrder(const EdgeWeightedDigraph &g)
    : marked_(g.V(), 0)
{
    for (int v=0; v<g.V(); v++) {
        if (!marked_[v]) {
            dfs(g, v);
        }
    }
    makeReversePostOrder();
}

void DepthFirstOrder::dfs(const Digraph &g, int v)
{
    marked_[v] = 1;
    pre_.push_back(v);

    for (int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            dfs(g, w);
        }
    }

    post_.push_back(v);
    reverse_post_stack_.push(v);
}

void DepthFirstOrder::dfs(const EdgeWeightedDigraph &g, int v)
{
    marked_[v] = 1;
    pre_.push_back(v);

    for (auto edge : g.GetAdj(v)) {
        int w = edge->To();
        if (!marked_[w]) {
            dfs(g, w);
        }
    }

    post_.push_back(v);
    reverse_post_stack_.push(v);
}

void DepthFirstOrder::makeReversePostOrder()
{
    while(!reverse_post_stack_.empty()) {
        reverse_post_.push_back(reverse_post_stack_.top());
        reverse_post_stack_.pop();
    }
}
