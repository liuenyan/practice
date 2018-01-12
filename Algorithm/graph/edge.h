#ifndef EDGE_H_INCLUED
#define EDGE_H_INCLUED

#include <iostream>

class Edge {
    int v_;
    int w_;
    double weight_;

public:
    Edge(int v, int w, double weight_);
    int Either() const { return v_; };
    int Other(int vertex) const;
    double Weight() const { return weight_; };
    int Compare(const Edge& that) const;
    bool operator<(const Edge & that) const { return Compare(that) < 0; };
    bool operator>=(const Edge & that) const { return !operator<(that); };
    bool operator>(const Edge& that) const { return Compare(that) > 0; };
    bool operator<=(const Edge& that) const { return !operator>(that); };
    bool operator==(const Edge& that ) const { return Compare(that) == 0; };

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};

std::ostream& operator<<(std::ostream& os, const Edge& edge);

#endif
