#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <fstream>
#include <vector>
#include <list>

// 无向图数据结构定义
class Graph {
    int V_; //顶点数
    int E_; //边数
    std::vector<std::list<int>> adj_; //邻接表
public:
    explicit Graph(int v); //创建一个含有 v 个顶点的无向图
    explicit Graph(std::ifstream &ifs);
    int V() const { return V_; };
    int E() const {  return E_; };
    void AddEdge(int v, int w); // 向图中添加一条边
    const std::list<int> &GetAdj(int v) const { return adj_[v]; };
};
#endif
