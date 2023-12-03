#include "funWithBFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.2: Nodes at distance k (BFS)
//=============================================================================
// TODO
vector<Person> FunWithBFS::nodesAtDistanceBFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;

    auto s = g->findVertex(source);

    if (s == nullptr) return res;

    queue<pair<Vertex<Person>*,int>> q;

    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
    }

    q.push({s,0});
    s->setVisited(true);
    while(!q.empty()) {
        auto tmp = q.front();
        q.pop();
        auto current = tmp.first;
        int distance = tmp.second;
        if(distance==k) {
            res.push_back(current->getInfo());
        }
        else if (distance > k) break;

        for (auto& w : current->getAdj()) {
            auto e = w.getDest();
            if(!e->isVisited()) {
                q.push({e,distance+1});
                e->setVisited(true);
            }
        }

    }


    return res;
}

//=============================================================================
// Exercise 2.2: Max New Children
//=============================================================================
// TODO
int FunWithBFS::maxNewChildren(const Graph<Person> *g, const Person &source, Person &info) {
    return 0;
}
