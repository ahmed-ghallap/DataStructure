// #include "graph.h"
#include "tree.h"


int main () {
    Graph graph;
    string cities[] = {"Alexandria", "Cairo", "Aswan", "El-bhera"};

    for (int i = 0; i < 4; i++) 
        graph.addVertix(cities[i]);

    graph.two_way(cities[0], cities[1], 300);
    graph.two_way(cities[0], cities[2], 500);
    graph.two_way(cities[0], cities[3], 150);
    // graph.two_way(cities[1], cities[2], 100);
    // graph.two_way(cities[1], cities[3], 100);

    // graph.depth(cities[0]);
}
