// بسم الله
#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct Graph  
{
    private:
        struct node {
             struct arc {
                double cost;
                node *to;
                arc *next = nullptr;
            };

            T data;
            arc *arcs = nullptr;
            node *next = nullptr;
            bool visited = false;
        };

        node *nodes = nullptr; 

    public:
        bool addNode(T data) {
            // check if node is already there
            // Then add to the list;
            node *ptr = new node;
            ptr->data = data;
            ptr->next = nodes;
            nodes = ptr;
            return true;
        }

        bool addArc(T from, T to, double cost) {
            typename Graph::node::arc *r;
            node *f = get_node(from);

            r->cost = cost;
            // check if get_node return valid address.
            r->to = get_node(to);

            r->next = f->arcs;
            f->arcs = r;
            return true; 
        }

        void display() {
            // for (node *tmp = nodes; tmp; tmp=tmp->next) {
                // if (!tmp) {
                    // break;
                // }
                // cout << tmp->data << ":\n";
                // for (typename Graph::node::arc *r = tmp->arcs; r; r=r->next) {
                //     if (!r) {
                //         break;
                //     }
                //     cout << "\t" << "from " << tmp->data 
                //     << ", to " << r->to->data 
                //     << " took " << r->cost << '\n';
                // }
            // }
        }

        node *get_node(T data) {
            for (node *tmp = nodes; tmp; tmp=tmp->next) {
                if (tmp->data == data)
                    return tmp;
            }
            return nullptr;
        }


};