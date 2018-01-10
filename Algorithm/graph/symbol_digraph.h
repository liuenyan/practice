#ifndef SYMBOL_DIGRAPH_H_INCLUED
#define SYMBOL_DIGRAPH_H_INCLUED

#include "digraph.h"
#include <map>
#include <vector>
#include <string>

class SymbolDigraph {
    Digraph *g_; //图对象
    std::map<std::string, int> st_; // 符号名 索引
    std::vector<std::string> keys_; //索引 符号名
public:
    SymbolDigraph(const std::string &filename, const std::string &delim);
    ~SymbolDigraph();
    bool Contains(const std::string &key) const;
    int Index(const std::string &key) const;
    const std::string &Name(int index) const;
    const Digraph &G() const;
};

#endif
