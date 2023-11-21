#include "funWithGraphs.h"


//=============================================================================
// Exercise 2: Vertex degrees
//=============================================================================
// Subexercise 2.1: outDegree
//=============================================================================
//TODO
int FunWithGraphs::outDegree(const Graph<int> g, const int &v) {
    auto v1 = g.findVertex(v);

    if (v1 == nullptr) return -1;

    return v1->getAdj().size();

}


//=============================================================================
// Subexercise 2.2: inDegree
//=============================================================================
//TODO
int FunWithGraphs::inDegree(const Graph<int> g, const int &v) {
    auto v1 = g.findVertex(v);
    if (v1 == nullptr) return -1;
    int counter = 0;
    for (auto vert : g.getVertexSet()) {
        for(auto edge : vert->getAdj()) {
            if(edge.getDest() == v1) {
                counter++;
            }
        }
    }

    return counter;

}

//=============================================================================
// Subexercise 2.3: weightedOutDegree
//=============================================================================
// TODO
int FunWithGraphs::weightedOutDegree(const Graph<int> g, const int &v) {
    return -1;
}
