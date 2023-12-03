#include "funWithDFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res);
vector<Person> FunWithDFS::nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;

    auto sourceVertex = g->findVertex(source);

    if (sourceVertex == nullptr) return res;

    for (auto& v : g->getVertexSet()) {
        v->setVisited(false);
    }

    nodesAtDistanceDFSVisit(g,sourceVertex,k,res);




    return res;
}

// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res) {

    v->setVisited(true);

    if(k== 0) {
        res.push_back(v->getInfo());
        return;
    }

    for(auto& e: v->getAdj()) {
        auto w = e.getDest();
        if(!w->isVisited()) {
            nodesAtDistanceDFSVisit(g, w, k-1, res);
        }
    }


}


//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
// TODO
bool dfsIsDAG(Vertex<int> *v);
bool FunWithDFS::isDAG(Graph<int> g) {
    return false;
}

// TODO
bool dfsIsDAG(Vertex<int> *v) {
    return false;
}
