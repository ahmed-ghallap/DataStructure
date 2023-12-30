// بسم الله
#include <iostream>
#include "help.h"


int main() {
    Graph<string> graph;

    graph.addNode("Alexandira");
    graph.addNode("Cairo");
    graph.addNode("Aswan");
    graph.addArc("Aswan", "Cairo", 500);
    graph.addArc("Aswan", "Alexandira", 200);
    
    graph.display();

}