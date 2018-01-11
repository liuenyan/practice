#include "edge_weighted_graph.h"

using namespace std;

EdgeWeightedGraph::EdgeWeightedGraph(int v)
    : V_(v)
    , E_(0)
    , adj_(v, list<shared_ptr<Edge>>())
{

}

EdgeWeightedGraph::EdgeWeightedGraph(ifstream& ifs)
    : V_(0)
    , E_(0)
{
    int E;
    ifs >> V_ >> E;

    for (int i=0; i<V_; i++) {
        adj_.push_back(list<shared_ptr<Edge>>());
    }

    for (int i=0; i<E; i++) {
        int v, w;
        double weight;
        ifs >> v >> w >> weight;
        AddEdge(make_shared<Edge>(Edge(v, w, weight)));
    }
}

void EdgeWeightedGraph::AddEdge(shared_ptr<Edge> edge)
{
    int v = edge->Either();
    int w = edge->Other(v);
    adj_[v].push_back(edge);
    adj_[w].push_back(edge);
    E_++;
}

vector<shared_ptr<Edge>> EdgeWeightedGraph::Edges() const
{
    vector<shared_ptr<Edge>> vec;
    for (int v = 0; v < V_; v++) {
        for (auto edge : GetAdj(v)) {
            if (edge->Other(v) > v) {
                vec.push_back(edge);
            }
        }
    }
    return vec;
}
#if 0
int main()
{
    ifstream ifs("tinyEWG.txt");
    EdgeWeightedGraph ewg(ifs);

    for (auto e : ewg.Edges()) {
        cout << *e << endl;
    }
    return 0;
}
#endif
