#include "edge_weighted_directed_cycle.h"
#include <stack>

using namespace std;

EdgeWeightedDirectedCycle::EdgeWeightedDirectedCycle(const EdgeWeightedDigraph& g)
    : marked_(g.V(), 0)
    , edge_to_(g.V(), nullptr)
    , on_stack_(g.V(), 0)
    , cycle_(0)
{
    for (int v = 0; v < g.V(); v++) {
        if (!marked_[v]) {
            dfs(g, v);
        }
    }
}

EdgeWeightedDirectedCycle::~EdgeWeightedDirectedCycle()
{
    delete cycle_;
}

void EdgeWeightedDirectedCycle::dfs(const EdgeWeightedDigraph& g, int v)
{
    marked_[v] = 1;
    on_stack_[v] = 1;

    for (auto edge : g.GetAdj(v)) {
        int w = edge->To();
        if (HasCycle()) {
            return;
        } else if (!marked_[w]) {
            edge_to_[w] = edge;
            dfs(g, w);
        } else if (on_stack_[w]) {
            stack<shared_ptr<DirectedEdge>> stack;
            cycle_ = new vector<shared_ptr<DirectedEdge>>();
            shared_ptr<DirectedEdge> x = edge;
            while (x->From() != w) {
                stack.push(x);
                x = edge_to_[x->From()];
            }
            stack.push(x);
            while (!stack.empty()) {
                cycle_->push_back(stack.top());
                stack.pop();
            }
        }
    }

    on_stack_[v] = 0;
}

bool EdgeWeightedDirectedCycle::HasCycle() const
{
    return cycle_ != nullptr;
}

const vector<shared_ptr<DirectedEdge>>& EdgeWeightedDirectedCycle::Cycle() const
{
    return *cycle_;
}
