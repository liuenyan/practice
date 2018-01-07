#include "depth_first_search.h"
#include <iostream>

using namespace std;

DepthFirstSearch::DepthFirstSearch(const Graph &g, int s)
    : count_(0), marked_(vector<int>(g.V(), 0))
{
    dfs(g, s);
}

DepthFirstSearch::~DepthFirstSearch()
{

}

void DepthFirstSearch::dfs(const Graph &g, int v)
{
    marked_[v] = 1;
    count_++;
    for(int w : g.GetAdj(v)) {
        if (!marked_[w]) {
            dfs(g, w);
        }
    }
}
