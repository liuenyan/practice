#include "topological.h"
#include "symbol_digraph.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3) {
        return -1;
    }

    SymbolDigraph sg(argv[1], argv[2]);
    Topological topo(sg.G());

    for (int w : topo.Order()) {
        cout << sg.Name(w) << endl;
    }

    return 0;
}
