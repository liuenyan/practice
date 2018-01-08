#ifndef TWO_COLOR_H_INCLUED
#define TWO_COLOR_H_INCLUED

#include "graph.h"
#include <vector>

// 双色问题，判断一幅图是否是二分图

class TwoColor {
    std::vector<int> marked_;
    std::vector<int> color_;
    bool two_colorable_;

    void dfs(const Graph &g, int s);
public:
    TwoColor(const Graph &g);
    bool IsBipartite() const { return two_colorable_; };
};

#endif
