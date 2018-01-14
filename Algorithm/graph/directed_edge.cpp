#include "directed_edge.h"

using namespace std;

DirectedEdge::DirectedEdge(int v, int w, double weight)
    : v_(v)
    , w_(w)
    , weight_(weight)
{
}

ostream& operator<<(ostream& os, const DirectedEdge& edge)
{
    os << edge.From() << "->" << edge.To() << ": " << edge.Weight();
    return os;
}
