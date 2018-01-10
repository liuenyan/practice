#include "directed_dfs.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream ifs(argv[1]);
    Digraph g(ifs);
    vector<int> sources;

    if(argc < 2) {
        return -1;
    }

    for (int i=2; i<argc; i++) {
        sources.push_back(atoi(argv[i]));
    }

    DirectedDFS reachable(g, sources);

    for (int v=0; v<g.V(); v++) {
        if (reachable.marked(v)) {
            cout << v << " ";
        }
    }
    cout << endl;

    return 0;
}
