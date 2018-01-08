#include "symbol_graph.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "usage: ./test_symbol_graph routes.txt \" \"" << endl;
        return -1;
    }
    char *filename = argv[1];
    char *delim = argv[2];

    SymbolGraph sg(filename, delim);
    const Graph &g = sg.G();

    string source;
    while (cin >> source) {
        for (int w : g.GetAdj(sg.Index(source))) {
            cout <<  sg.Name(w) << " ";
        }
        cout << endl;
    }

    return 0;
}
