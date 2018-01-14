#ifndef EDGE_WEIGHTED_DIGRAPH_H_INCLUDED
#define EDGE_WEIGHTED_DIGRAPH_H_INCLUDED

#include "directed_edge.h"
#include <list>
#include <memory>
#include <vector>
#include <fstream>

class EdgeWeightedDigraph {
    int V_; //顶点数
    int E_; //边数
    std::vector<std::list<std::shared_ptr<DirectedEdge>>> adj_; // 邻接表

public:
    explicit EdgeWeightedDigraph(int v);
    explicit EdgeWeightedDigraph(std::ifstream& ifs);
    void AddEdge(std::shared_ptr<DirectedEdge> edge);
    int V() const { return V_; };
    int E() const { return E_; };
    const std::list<std::shared_ptr<DirectedEdge>>& GetAdj(int v) const { return adj_[v]; };
    std::vector<std::shared_ptr<DirectedEdge>> Edges() const;
};

#endif
