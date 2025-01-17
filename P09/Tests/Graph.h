/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <cstddef>
#include <vector>
#include <queue>

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;


/****************** Provided structures  ********************/

template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // list of outgoing edges
	bool visited;          // auxiliary field
    bool processing;       // auxiliary field

    void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);
public:
	Vertex(T in);
    T getInfo() const;
    void setInfo(T in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge<T>> &getAdj() const;
    void setAdj(const vector<Edge<T>> &adj);
    friend class Graph<T>;
};

template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
    Vertex<T> *getDest() const;
    void setDest(Vertex<T> *dest);
    double getWeight() const;
    void setWeight(double weight);
    friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
public:
    Vertex<T> *findVertex(const T &in) const;
    int getNumVertex() const;
	bool addVertex(const T &in);
	bool removeVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeEdge(const T &sourc, const T &dest);
    vector<Vertex<T> * > getVertexSet() const;
    int inDegree(const T &v) const;
};

/****************** Provided constructors and functions ********************/

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
    return vertexSet;
}

template<class T>
T Vertex<T>::getInfo() const {
    return info;
}

template<class T>
void Vertex<T>::setInfo(T in) {
    Vertex::info = in;
}

template<class T>
bool Vertex<T>::isProcessing() const {
    return processing;
}

template<class T>
void Vertex<T>::setProcessing(bool p) {
    Vertex::processing = p;
}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
void Edge<T>::setDest(Vertex<T> *d) {
    Edge::dest = d;
}

template<class T>
double Edge<T>::getWeight() const {
    return weight;
}

template<class T>
void Edge<T>::setWeight(double weight) {
    Edge::weight = weight;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

template <class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template <class T>
void Vertex<T>::setVisited(bool v) {
    Vertex::visited = v;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

template <class T>
void Vertex<T>::setAdj(const vector<Edge<T>> &adj) {
    Vertex::adj = adj;
}


//=============================================================================
// Exercise 1: Graph implementation
//=============================================================================
// Subexercise 1.1: addVertex
//=============================================================================
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
//TODO
template <class T>
bool Graph<T>::addVertex(const T &in) {
    // HINT: use the findVertex function to check if a vertex already exists

    if(findVertex(in) != NULL) return false;

    Vertex<T>* new_vert = new Vertex<T>(in);
    vertexSet.push_back(new_vert);
    return true;

}

//=============================================================================
// Subexercise 1.2: addEdge
//=============================================================================
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
//TODO
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    // HINT: use findVertex to obtain the actual vertices
    auto v1 = findVertex(sourc);
    auto v2 =  findVertex(dest);
    if (v1== NULL || v2 == NULL) return false;

    v1->addEdge(v2,w);

    return true;

}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
//TODO
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    adj.push_back(Edge<T>(d,w));
}

//=============================================================================
// Subexercise 1.3: removeEdge
//=============================================================================
/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
//TODO
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    // HINT: Use "findVertex" to obtain the actual vertices.
    // HINT: Use "removeEgeTo" to actually remove the edge.

    auto v1 = findVertex(sourc);
    auto v2 =  findVertex(dest);
    if (v1== NULL || v2 == NULL) return false;

    if(v1->removeEdgeTo(v2)) return true;
    return false;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
//TODO
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    // HINT: use an iterator to scan the "adj" vector and then erase the edge.

    for (auto edge = adj.begin(); edge != adj.end(); edge++) {
        if(edge->dest==d) {
            adj.erase(edge);
            edge--;
            return true;
        }
    }
	return false;
}

//=============================================================================
// Subexercise 1.4: removeVertex
//=============================================================================
/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
//TODO
template <class T>
bool Graph<T>::removeVertex(const T &in) {

    auto vertex = findVertex(in);


    if (vertex == NULL) return false;

    vertex->adj.clear();

    for (auto tmpVert = vertexSet.begin(); tmpVert != vertexSet.end(); tmpVert++) {

    if(vertex != *tmpVert) {
        (*tmpVert)->removeEdgeTo(vertex);
    }
    else {
        vertexSet.erase(tmpVert);
    }
    }
    return true;

/*
     for (auto it = vertexSet.begin(); it != vertexSet.end(); it++) {
     if((*it)->info == in) {
         auto v = *it;
         vertexSet.erase(it);
         for (auto u: vertexSet) u->removeEdgeTo(v);
         delete (v);
         return true;
     }
     return false;
*/




    // HINT: use an iterator to scan the "vertexSet" vector and then erase the vertex.
    // HINT: take advantage of "removeEdgeTo" to remove incoming edges.

}

#endif /* GRAPH_H_ */



