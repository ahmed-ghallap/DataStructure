// بسم الله
#include <iostream>
#include <stack>
#include "tree.h" 

using namespace std;

Tree from_infix(string eq) {
    stack<node *> stack_of_nodes;

    for (int i = 0; i < eq.length(); i++) {
        if (is_close_prant(eq[i])) {
            node *right = stack_of_nodes.top();
            stack_of_nodes.pop();
            node *middle = stack_of_nodes.top();
            stack_of_nodes.pop();
            node *left = stack_of_nodes.top();
            stack_of_nodes.pop();

            middle->right = right;
            middle->left = left;

            stack_of_nodes.push(middle);
        } else {
            node *new_node = (node *) malloc(sizeof(node));
            new_node->data = eq[i];
            stack_of_nodes.push(new_node);
        }
    }   
    Tree roro;
    node * tmp = stack_of_nodes.top(); 
    roro.root = tmp;
    return roro;
}

int main() {
    string eq;
    cout << "eq: ";
    getline(cin, eq);

    string newEq;
    for (int i = 0; i < eq.length(); i++) {
        if (eq[i] != ' ') {
            newEq += (eq[i]);
        }
    }

    Tree tree = from_infix(newEq);

    cout << "\ninorder:\n";
    cout << eq;
    cout << endl;

    cout << "prefix:\n";
    tree.preorder(tree.root);
    cout << endl;

    cout << "postfix:\n";
    tree.postorder(tree.root);
    cout << endl;
}


