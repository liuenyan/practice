#ifndef SHARED_PTR_EDGE_COMPARE_H_INCLUED
#define SHARED_PTR_EDGE_COMPARE_H_INCLUED

#include "edge.h"
#include <memory>

class SharedPtrEdgeCompare {
    bool reverse_;

public:
    explicit SharedPtrEdgeCompare(bool reverse = false)
        : reverse_(reverse){};
    bool operator()(const std::shared_ptr<Edge> lhs, const std::shared_ptr<Edge> rhs)
    {
        if (reverse_) {
            return lhs->Compare(*rhs) >= 0;
        } else {
            return lhs->Compare(*rhs) < 0;
        }
    };
};

#endif
