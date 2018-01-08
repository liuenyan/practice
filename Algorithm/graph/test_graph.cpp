#include "graph.h"
#include <iostream>

#include "depth_first_search.h"
#include "depth_first_paths.h"
#include "breadth_first_paths.h"
#include "connected_components.h"

using namespace std;

void test_depth_dirst_search()
{
    ifstream ifs("tinyG.txt");
    Graph g(ifs);

    DepthFirstSearch dfs(g, 1);

    for(int i=0; i<g.V(); i++) {
        if (dfs.Marked(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    if (dfs.Count() < g.V()) {
        cout << "NOT Connect" << endl;
    }
}

void test_depth_first_paths()
{
    ifstream ifs("tinyCG.txt");
    Graph g(ifs);
    int s = 0;
    DepthFirstPaths paths(g, s);

    for(int i=0; i<g.V(); i++) {
        if (paths.HasPathTo(i)) {
            cout << s <<  " to " << i << " : ";
            auto vec = paths.PathTo(i);
            for (int j : vec) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}

void test_breadth_first_paths()
{
    ifstream ifs("tinyCG.txt");
    Graph g(ifs);
    int s = 0;
    BreadthFirstPaths paths(g, s);

    for(int i=0; i<g.V(); i++) {
        if (paths.HasPathTo(i)) {
            cout << s <<  " to " << i << " : ";
            auto vec = paths.PathTo(i);
            for (int j : vec) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}

void test_connected_components()
{
    ifstream ifs("tinyG.txt");
    Graph g(ifs);
    ConnectedComponents cc(g);

    int M = cc.Count();
    cout << M << " components" << endl;

    vector<vector<int>> components(M, vector<int>());
    for(int i=0; i<g.V(); i++) {
        components[cc.Id(i)].push_back(i);
    }

    for (int i=0; i<M; i++) {
        for (size_t j=0; j<components[i].size(); j++) {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    //test_depth_dirst_search();
    //test_depth_first_paths();
    //test_breadth_first_paths();
    test_connected_components();
    return 0;
}
