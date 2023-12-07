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
    int max = 0;
    for(auto& v : g->getVertexSet()) {
        v->setVisited(false);
        for (auto& e: v->getAdj()) {
            Vertex<int>*  w = e.getDest();
            g->addEdge(w->getInfo(), v->getInfo(),0);
        }
    }

    for (auto& v : g->getVertexSet()) {
        if(!v->isVisited()) {
            auto x = dfsGC(v);
            if(x >max) max = x;

        }
    }
    return max;
}

int dfsGC(Vertex<int> *v) {
    v->setVisited(true);
    int count = 1;
    for (auto& e : v->getAdj()) {
        auto w = e.getDest();
        if(!w->isVisited()) {
            count+=dfsGC(w);
        }
    }

    return count;
}


//=============================================================================
// Exercise 2.3: Strongly Connected Components
//=============================================================================
// TODO
void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i);
list<list<int>> funWithGraphs::scc(Graph<int> *g){
    list<list<int>> res;
    stack<int> s;
    int i = 0;

    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
        v->setProcessing(false);
    }

    for (auto v : g->getVertexSet()) {
        if(!v->isVisited()) {
            dfs_scc(g,v,s,res,i);
        }
    }

    return res;
}

void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i){
    v->setVisited(true);
    v->setProcessing(true);
    v->setNum(i);
    v->setLow(i);
    i++;
    s.push(v->getInfo());

    for(auto& e : v->getAdj()) {
        auto w = e.getDest();

        if (!w->isVisited()) {
            dfs_scc(g, w, s, l, i);
            v->setLow(min(v->getLow(),w->getLow()));
        }

        else if (w->isProcessing()) {
            v->setLow(min(v->getLow(),w->getNum()));
        }
    }

    if(v->getNum() == v->getLow()) {
        list<int> component;

        while (true) {
            int node = s.top();
            s.pop();
            component.push_back(node);
            if(node == v->getInfo()) {
                break;
            }
        }

    l.push_back(component);
    }

    v->setProcessing(false);

    }




//=============================================================================
// Exercise 2.4: Articulation Points
//=============================================================================
// TODO
void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &res, int &i);
unordered_set<int> funWithGraphs::articulationPoints(Graph<int> *g) {
    unordered_set<int> res;
    stack<int> s;
    int i = 0;


    for (auto & v : g->getVertexSet()) {
        v->setVisited(false);
    }

    for (auto & v : g->getVertexSet()) {
        dfs_art(g,v,s,res,i);
    }


    return res;
}


// necessário introduzir children para verificar se a raiz é um articulation point
void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &l, int &i) {
    v->setVisited(true);
    v->setNum(i);
    v->setLow(i);
    i++;
    s.push(v->getInfo());
    int children = 0;

    for (auto &e: v->getAdj()) {
        auto w = e.getDest();

        if (!w->isVisited()) {
            children++;
            dfs_art(g, w, s, l, i);
            v->setLow(min(v->getLow(), w->getLow()));
            if (v->getNum() != 0 && w->getLow()>= v->getNum()) {
                l.insert(v->getInfo());
            }
        } else if (w->getNum() < v->getLow()) {
            v->setLow(min(v->getLow(), w->getNum()));
        }
    }

    s.pop();


    if (v->getNum() == 0 && children > 1) {
        l.insert(v->getInfo());
    }
}

/*
        while(!s.empty() && s.top() != v->getInfo()) {
            l.insert(s.top());
            s.pop();
        }
        if(!s.empty()) {
            s.pop();
        }
    }
*/