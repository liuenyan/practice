#ifndef SYMBOL_GRAPH_H_INCLUED
#define SYMBOL_GRAPH_H_INCLUED

#include "graph.h"
#include <map>
#include <vector>
#include <string>

class SymbolGraph {
    Graph *g_; //图对象
    std::map<std::string, int> st_; // 符号名 索引
    std::vector<std::string> keys_; //索引 符号名
public:
    SymbolGraph(const std::string &filename, const std::string &delim);
    ~SymbolGraph();
    bool Contains(const std::string &key) const;
    int Index(const std::string &key) const;
    const std::string &Name(int index) const;
    const Graph &G() const;
};

#endif
