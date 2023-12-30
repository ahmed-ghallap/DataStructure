// بسم الله
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
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

    void breadth (string s) {
        queue<vertex *> pipline;
        list<vertex *> visited;
        vertex *start = get_vertex(s);
        pipline.push(start);
        visited.push_back(start);
        while (!pipline.empty()) {
            vertex *r = pipline.front();pipline.pop();
            cout << r->data << ") ";
            for 
            (
                vertex::edge * e = r->edges;
                e;
                e = e->next
            )
            {
                if (!search(e->to, visited)) {
                    pipline.push(e->to);
                    visited.push_back(e->to);
                    cout << e->to->data << ' ';
                }   
            }
            cout << endl; 
        }

    }

    void depth (string s) {
        stack<vertex *> pipline;
        list<vertex *> visited;

        vertex *start = get_vertex(s);
        pipline.push(start);
        visited.push_back(start);

        while (!pipline.empty()) {
            vertex *tmp = pipline.top(); pipline.pop();
            for (
                    vertex::edge * e = print_node(tmp);
                    e;
                    e = e->next
                )
                {
                    if (!search(e->to, visited)) {
                        pipline.push(e->to);
                        visited.push_back(e->to);
                    }
                }
        }
        cout << endl;
    }
    
    vertex::edge *print_node(vertex *v) {
        if (v->edges) {
            cout << v->data << " => ";
        }
        return v->edges;
    }

    bool search(vertex *v, list<vertex *>l) {
        for (auto i : l) {
            if (i == v)
                return true;
        }
        return false;
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
        vertex* ptr = new vertex;
        ptr->data = data;

        ptr->next = vertecies;
        vertecies = ptr;
        return ptr;
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



    void load_from_file(string filename) {
        ifstream file;
        file.open(filename);
        string s;
        getline(file, s);

        string from, to;
        double cost;
        while (!file.eof()) {
            file >> from >> to >> cost;
            two_way(from, to, cost);
        }

    }


    void min_sapn_tree (string s) {
        stack<vertex *> pipline;
        list<vertex *> visited;

        vertex *start = get_vertex(s);
        pipline.push(start);
        visited.push_back(start);

        while (!pipline.empty()) {
            // cout << "size: " << pipline.size() << endl;
            vertex *tmp = pipline.top(); pipline.pop();
            vertex::edge * e = print_node(tmp);
            list<vertex::edge *> unvisiteds;
            for ( ;e ;e=e->next)
            {
                if (!search(e->to, visited)) {
                    unvisiteds.push_back(e);
                }
            }
            vertex::edge *smallest = unvisiteds.front();
            for (auto unvisited: unvisiteds) {
                if (unvisited->cost < smallest->cost) 
                    smallest = unvisited;
            }
            if (smallest) {
                pipline.push(smallest->to);
                visited.push_back(smallest->to);
                unvisiteds.clear();
            }
        }
        cout << endl;
    }
};


    