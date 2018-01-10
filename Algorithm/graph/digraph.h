#ifndef DIGRAPH_H_INCLUED
#define DIGRAPH_H_INCLUED

#include <list>
#include <vector>
#include <fstream>

// 有向图数据结构定义
class Digraph {
private:
    int V_; //顶点数
    int E_; //边数
    std::vector<std::list<int>> adj_; //邻接表
public:
    explicit Digraph(int v);
    explicit Digraph(std::ifstream &ifs);
    // 增加一条从v指向w的边
    void AddEdge(int v, int w);
    // 获得顶点数
    int V() const { return V_; };
    // 获得边数
    int E() const { return E_; };
    // 获得顶点的邻接表
    const std::list<int>& GetAdj(int v) const { return adj_[v]; };
    // 生成反向图
    Digraph Reverse() const;
};

#endif
