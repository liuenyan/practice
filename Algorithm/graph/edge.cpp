#include "edge.h"
#include <stdexcept>

using namespace std;

Edge::Edge(int v, int w, double weight)
    : v_(v)
    , w_(w)
    , weight_(weight)
{
}

int Edge::Compare(const Edge& that) const
{
    if (weight_ < that.weight_) {
        return -1;
    } else if (weight_ > that.weight_) {
        return 1;
    }
    return 0;
}

ostream& operator<<(ostream& os, const Edge& edge)
{
    os << edge.v_ << "-" << edge.w_ << ": " << edge.Weight();
    return os;
}

int Edge::Other(int vertex) const
{
    if (vertex == v_) {
        return w_;
    }
    if (vertex == w_) {
        return v_;
    } else {
        throw runtime_error("Inconsistent edge");
    }
}
