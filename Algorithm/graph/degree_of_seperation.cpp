#include "symbol_graph.h"
#include "breadth_first_paths.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 4) {
        return -1;
    }

    SymbolGraph sg(argv[1], argv[2]);

    if (!sg.Contains(argv[3])) {
        cout << argv[3] << " not in database." << endl;
        return -1;
    }

    const Graph &g = sg.G();
    int s = sg.Index(argv[3]);
    BreadthFirstPaths bfs(g, s);

    string sink; //人名

    while(getline(cin, sink)) {
        if (!sg.Contains(sink)) {
            cout << sink << " is not in database." << endl;
            continue;
        }
        int v = sg.Index(sink);
        if (bfs.HasPathTo(v)) {
            vector<int> vec = bfs.PathTo(v);
            for (int w : vec) {
                cout << "\t" << sg.Name(w) << endl;
            }
        } else {
            cout << "NOT Connected" << endl;
        }
    }
    return 0;
}
