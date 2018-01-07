#include "graph.h"
#include <iostream>

#include "depth_first_search.h"
#include "depth_first_paths.h"

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

void test_depth_dirst_paths()
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

int main()
{
    //test_depth_dirst_search();
    test_depth_dirst_paths();
    return 0;
}
