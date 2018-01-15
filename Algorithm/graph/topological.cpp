#include "topological.h"
#include "directed_cycle.h"
#include "depth_first_order.h"
#include "edge_weighted_directed_cycle.h"

using namespace std;

Topological::Topological(const Digraph &g)
    : order_(0)
{
    DirectedCycle cycle_finder(g);
    if (!cycle_finder.HasCycle()) {
        DepthFirstOrder dfs(g);
        order_ = new vector<int>(dfs.ReversePostOrder());
    } else {
        order_ = new vector<int>();
    }
}

Topological::Topological(const EdgeWeightedDigraph &g)
    : order_(0)
{
    EdgeWeightedDirectedCycle cycle_finder(g);
    if (!cycle_finder.HasCycle()) {
        DepthFirstOrder dfs(g);
        order_ = new vector<int>(dfs.ReversePostOrder());
    } else {
        order_ = new vector<int>();
    }
}

Topological::~Topological()
{
    delete order_;
}
