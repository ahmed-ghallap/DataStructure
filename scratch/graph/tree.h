// بسم الله
#include "graph.h"

struct Tree {
    struct node {
        string data;
        list<node *>children;
    };
    node *root = nullptr;

};

Tree from_graph(Graph g, Graph::vertex *city) {
    Tree tree;
    stack<Graph::vertex *> s;
    s.push(g.vertecies);
    // Graph::vertex *tmp = g.vertecies;
    // Graph::vertex::edge *e = city->edges;
    // for ( ;e ;e=e->next) {
    //     if (e->cost < smallestEdge->cost) 
    //         smallestEdge = e;
    // }
    while (!s.empty()) {
        Graph::vertex *tmp = s.top();s.pop();
        Graph::vertex::edge *e = tmp->edges;

}