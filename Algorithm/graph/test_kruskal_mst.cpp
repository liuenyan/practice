#include "kruskal_mst.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return -1;
    }
    ifstream ifs(argv[1]);
    EdgeWeightedGraph g(ifs);
    KruskalMST mst(g);

    for (auto e : mst.Edges()) {
        cout << *e << endl;
    }

    cout << mst.Weight() << endl;

    return 0;
}
