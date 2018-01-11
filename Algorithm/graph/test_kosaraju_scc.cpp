#include "digraph.h"
#include "kosaraju_scc.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        return -1;
    }

    ifstream ifs(argv[1]);
    Digraph g(ifs);
    KosarajuSCC scc(g);

    cout << scc.Count() << " components" << endl;

    vector<vector<int>> vec(scc.Count(), vector<int>());
    for (int v = 0; v < g.V(); v++) {
        vec[scc.Id(v)].push_back(v);
    }

    for (int i = 0; i < scc.Count(); i++) {
        for (int v : vec[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
