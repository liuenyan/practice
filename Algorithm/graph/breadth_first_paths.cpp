#include "breadth_first_paths.h"
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

BreadthFirstPaths::BreadthFirstPaths(const Graph &g, int s)
    : s_(s), marked_(g.V(), 0), edge_to_(g.V(), 0)
{
    bfs(g, s);
}

void BreadthFirstPaths::bfs(const Graph &g, int s)
{
    queue<int> q;
    marked_[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int w : g.GetAdj(v)) {
            if(!marked_[w]) {
                marked_[w] = 1;
                edge_to_[w] = v;
                q.push(w);
            }
        }
    }
}


vector<int> BreadthFirstPaths::PathTo(int v) const
{
    vector<int> vec;
    if(!marked_[v]) {
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
