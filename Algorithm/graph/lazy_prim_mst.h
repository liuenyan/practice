#ifndef LAZY_PRIM_MST_H_INCLUED
#define LAZY_PRIM_MST_H_INCLUED

#include "edge_weighted_graph.h"
#include "shared_ptr_edge_compare.h"
#include <memory>
#include <queue>
#include <vector>

class LazyPrimMST {
    std::vector<int> marked_; //标记最小生成树的顶点
    std::vector<std::shared_ptr<Edge>> mst_; //最小生成树的边
    SharedPtrEdgeCompare cmp_; //用于堆中元素的比较的Functor
    //横切边(包括失效的边)的小堆
    std::priority_queue<std::shared_ptr<Edge>, std::vector<std::shared_ptr<Edge>>, SharedPtrEdgeCompare> pq_;

    void visit(const EdgeWeightedGraph& g, int v);

public:
    LazyPrimMST(const EdgeWeightedGraph& g);
    const std::vector<std::shared_ptr<Edge>>& Edges() const;
    double Weight() const;
};

#endif
