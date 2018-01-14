#include "dijkstra_sp.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3) {
        return -1;
    }
    ifstream ifs(argv[1]);
    EdgeWeightedDigraph g(ifs);
    int s = atoi(argv[2]);
    DijkstraSP sp(g, s);

    for (int v = 0; v < g.V(); v++) {
        cout << s << " to " << v << " (" << sp.DistTo(v) <<")";
        if (sp.HasPathTo(v)) {
            for (auto edge : sp.PathTo(v)) {
                cout << *edge << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
