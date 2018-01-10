#include "directed_cycle.h"
#include <stack>

using namespace std;

DirectedCycle::DirectedCycle(const Digraph& g)
    : marked_(g.V(), 0)
    , edge_to_(g.V(), 0)
    , on_stack_(g.V(), 0)
    , cycle_(0)
{
    for (int v = 0; v < g.V(); v++) {
        if (!marked_[v]) {
            dfs(g, v);
        }
    }
}

DirectedCycle::~DirectedCycle()
{
    delete cycle_;
}

void DirectedCycle::dfs(const Digraph& g, int v)
{
    marked_[v] = 1;
    on_stack_[v] = 1;

    for (int w : g.GetAdj(v)) {
        if (HasCycle()) {
            return;
        } else if (!marked_[w]) {
            edge_to_[w] = v;
            dfs(g, w);
        } else if (on_stack_[w]) {
            stack<int> stack;
            cycle_ = new vector<int>();
            for (int x = v; x != w; x = edge_to_[w]) {
                stack.push(x);
            }
            stack.push(w);
            stack.push(v);
            while (!stack.empty()) {
                cycle_->push_back(stack.top());
                stack.pop();
            }
        }
    }

    on_stack_[v] = 0;
}

bool DirectedCycle::HasCycle() const
{
    return cycle_ != nullptr;
}

const vector<int>& DirectedCycle::Cycle() const
{
    return *cycle_;
}
