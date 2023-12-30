// بسم الله
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

struct Graph {
    struct vertex {
        struct edge {
            double cost;
            vertex *to;
            edge *next = nullptr;
        };
        string data;
        edge *edges = nullptr;
        vertex *next = nullptr;
    };

    vertex *vertecies;

    void depth (string s) {
        stack<vertex *> pipline;
        list<vertex *> visited;

        vertex *start = get_vertex(s);
        pipline.push(start);

        while (!pipline.empty()) {
            vertex *tmp = pipline.top();
            pipline.pop();
            visited.push_back(tmp);
            for (
                    vertex::edge * e = print_node(tmp);
                    e;
                    e = e->next
                )
                {
                    // if to not in visited list.

                    bool there = false;
                    for (auto i : visited) {
                        if (i == e->to) {
                            there = true;
                        }
                    }
                    if (!there)  {
                        pipline.push(e->to);
                        // cout << e->to->data << " is unvisited \n";
                        visited.push_back(tmp);
                    }
                }
        }

        // for (auto i : visited) {
        //     cout << i->data << endl;
        // }
        
    }

    vertex::edge *print_node(vertex *v) {
        cout << v->data << endl;
        return v->edges;
    }

    void addVertix(string data) {
        vertex* ptr = new vertex;
        ptr->data = data;

        ptr->next = vertecies;
        vertecies = ptr;
    }

    vertex *get_vertex(string data) {
        for (vertex *tmp = vertecies; tmp; tmp=tmp->next) {
            if (tmp->data == data) {
                return tmp;
            }
        }
        return nullptr;
    }
    void two_way(string f,string to, double cost) {
        one_way (f, to, cost);
        one_way (to, f, cost);
    }

    void one_way(string f, string to, double cost) {
        vertex *from = get_vertex(f);

        vertex::edge *tmp = new vertex::edge ;
        tmp->to = get_vertex(to);
        tmp->cost = cost;

        tmp->next = from->edges;
        from->edges = tmp;
    }

    void display () {
        for (vertex *tmp = vertecies; tmp; tmp=tmp->next) {
            if (tmp->edges) {
                cout << tmp->data << " goes to: (";
                vertex::edge *i = tmp->edges;
                for ( ; i->next; i=i->next) {
                    cout <<  i->to->data << " with (" << i->cost << ')' << ", ";
                }
                cout << i->to->data << " with (" << i->cost << ')' <<  ")\n";
            }

        }
    }

    void load_from_file(string file) {
        // emptye for now
    }

  

};


    