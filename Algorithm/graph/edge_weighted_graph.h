#ifndef EDGE_WEIGHTED_GRAPH_H_INCLUDED
#define EDGE_WEIGHTED_GRAPH_H_INCLUDED

#include "edge.h"
#include <fstream>
#include <list>
#include <memory>
#include <vector>

class EdgeWeightedGraph {
    int V_; //顶点数
    int E_; //边数
    std::vector<std::list<std::shared_ptr<Edge>>> adj_; //邻接表

public:
    EdgeWeightedGraph(int v);
    EdgeWeightedGraph(std::ifstream& ifs);
    void AddEdge(std::shared_ptr<Edge> edge);
    int V() const { return V_; };
    int E() const { return E_; };
    const std::list<std::shared_ptr<Edge>>& GetAdj(int v) const { return adj_[v]; };
    std::vector<std::shared_ptr<Edge>> Edges() const;
};

#endif
