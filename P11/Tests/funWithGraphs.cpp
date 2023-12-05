#include "funWithGraphs.h"

//=============================================================================
// Exercise 2.1: Connected Components
//=============================================================================
// TODO
void dfsVisit(Vertex<int> *v);
int funWithGraphs::connectedComponents(Graph<int> *g) {
    for(auto& v : g->getVertexSet()) {
        v->setVisited(false);
        for (auto& e: v->getAdj()) {
            Vertex<int>*  w = e.getDest();
            g->addEdge(w->getInfo(), v->getInfo(),0);
        }
    }

    int count  = 0;
    for (auto& v : g->getVertexSet()) {
        if(!v->isVisited()) {
            dfsVisit(v);
            count++;
        }
    }


    return count;
}

void dfsVisit(Vertex<int> *v) {
    v->setVisited(true);

    for (auto& e : v->getAdj()) {
        auto w = e.getDest();
        if(!w->isVisited()) {
            dfsVisit(w);
        }
    }

}


//=============================================================================
// Exercise 2.2: Giant Component
//=============================================================================
// TODO
int dfsGC(Vertex<int> *v);
int funWithGraphs::giantComponent(Graph<int> *g) {
    return 0;
}

int dfsGC(Vertex<int> *v) {
    return 0;
}


//=============================================================================
// Exercise 2.3: Strongly Connected Components
//=============================================================================
// TODO
void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i);
list<list<int>> funWithGraphs::scc(Graph<int> *g){
    list<list<int>> res;

    return res;
}

void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i){}


//=============================================================================
// Exercise 2.4: Articulation Points
//=============================================================================
// TODO
void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &res, int &i);
unordered_set<int> funWithGraphs::articulationPoints(Graph<int> *g) {
    unordered_set<int> res;

    return res;
}

void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &l, int &i){}