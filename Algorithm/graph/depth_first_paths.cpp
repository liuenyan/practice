#include "depth_first_paths.h"
#include <stack>
#include <iostream>

using namespace std;

DepthFirstPaths::DepthFirstPaths(const Graph &g, int s)
    : s_(s), marked_(g.V(), 0), edge_to_(g.V(), 0)
{
    dfs(g, s);
}

void DepthFirstPaths::dfs(const Graph &g, int v)
{
    marked_[v] = 1;
    for(int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            edge_to_[w] = v;
            dfs(g, w);
        }
    }
}

vector<int> DepthFirstPaths::PathTo(int v) const
{
    vector<int> vec;
    if (!HasPathTo(v)) {
        return vec;
    }

    stack<int> stack;
    for (int w = v; w != s_; w = edge_to_[w]) {
        stack.push(w);
    }
    stack.push(s_);

    while(!stack.empty()) {
        vec.push_back(stack.top());
        stack.pop();
    }
    return vec;
}
