#include <iostream>

using namespace std;

struct node {
    char data;
    node *left = nullptr;
    node *right = nullptr;

};

struct stackNode {
    node *data;
    stackNode *next = nullptr;
};

bool is_oprand(char c);

struct Tree {
    node *root = nullptr;

    void inorder(node *r) { 
        // <left><root><right>
        if (r == nullptr) {
            return;
        }
        inorder(r->left);
        cout << r->data << ' ';
        inorder(r->right);
    }

    void preorder(node *r) {
        // <root><left><right>
        if (r == nullptr) {
            return;
        }
        cout << r->data << ' ';
        preorder(r->left);
        preorder(r->right);
    }
    void postorder(node *r) {
        // <right><left><root>
        if (r == nullptr) {
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout << r->data << ' ';
    }
};

bool is_oprand(char c) {
    return (c == '*' || c == '+' || c == '-' || c == '/' || '%') ;
}

bool is_prant(char c) {
    return (c == '(' || c == ')');
}

bool is_close_prant(char c) {
    return (c == ')');
}