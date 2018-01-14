#ifndef DIRECTED_EDGE_H_INCLUDED
#define DIRECTED_EDGE_H_INCLUDED

#include <iostream>

class DirectedEdge {
    int v_;
    int w_;
    double weight_;

public:
    DirectedEdge(int v, int w, double weight);
    int From() const { return v_; };
    int To() const { return w_; };
    double Weight() const { return weight_; };
};

std::ostream& operator<<(std::ostream& os, const DirectedEdge& edge);

#endif
