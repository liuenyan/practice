#include "symbol_graph.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

namespace {
vector<string> split(const string &s, const string &delim)
{
    vector<string> v;
    string::size_type pos1 = 0;
    string::size_type pos2 = s.find(delim);

    while(pos2 != string::npos) {
        v.push_back(s.substr(pos1, pos2 -pos1));
        pos1 = pos2 + delim.size();
        pos2 = s.find(delim, pos1);
    }

    v.push_back(s.substr(pos1));
    return v;
}
};

SymbolGraph::SymbolGraph(const string &filename, const string &delim)
{
    char line[256];
    ifstream ifs(filename);
    int count = 0;

    // 创建节点名称和节点编号的对应关系
    while(ifs.getline(line, 256)) {
        auto vec = split(line, delim);
        for (auto &key : vec) {
            if (st_.find(key) == st_.end()) {
                st_[key] = count;
                keys_.push_back(key);
                count++;
            }
        }
    }

    // 创建无向图
    ifs.clear();
    ifs.seekg(0, ifs.beg);
    g_ = new Graph(count);
    while(ifs.getline(line, 256)) {
       auto vec = split(line, delim);
        int v = st_[vec[0]];
        for (vector<string>::size_type i=1; i<vec.size(); i++) {
            int w = st_[vec[i]];
            g_->AddEdge(v, w);
        }
    }
}

SymbolGraph::~SymbolGraph()
{
    delete g_;
}

bool SymbolGraph::Contains(const std::string &key) const
{
    return st_.find(key) != st_.end();
};

int SymbolGraph::Index(const std::string &key) const
{
    return st_.at(key);
}

const std::string &SymbolGraph::Name(int index) const
{
    return keys_[index];
}

const Graph &SymbolGraph::G() const
{
    return *g_;
}
