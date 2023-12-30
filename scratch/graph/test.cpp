#include "tree.h"


int main (int argc, char *argv[]) {
    Graph graph;

    graph.load_from_file(argv[2]);
    
    system("clear");
    char op;
    while (cin >> op) {
        system("clear");
        switch (op) {
            case 'd' :
                graph.display();
                continue;
            case 'm' : {
                string s;
                cout << "start point: ";
                cin >> s;
                graph.min_sapn_tree(s);
                continue;
            }
            case 's' : {
                string s;
                cout << "start point: ";
                cin >> s;
                graph.depth(s);
                continue;
            }
            case 'q' : {
                string s;
                cout << "start point: ";
                cin >> s;
                graph.breadth(s);
                continue;
            }
        }
    }
}
