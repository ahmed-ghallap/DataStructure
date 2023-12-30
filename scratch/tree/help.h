// بسم الله
#include <iostream>

using namespace std;

template <typename T>
struct Tree {
    struct Node {
        T data;
        Node *right = nullptr;
        Node *left = nullptr; 
    };

    Node *root = nullptr;

    void inorder () {
        _inorder(root);
    }

    void _inorder (Node *r) {
        if (!r) 
            return;
        cout << r->data << endl;
        _inorder(r->left);
        _inorder(r->right);
    }

    void add(T data) {
        _add(data, root);

    }

    void _add (T data, Node *root) {
        if (root == nullptr) {
            cout << "hi\n";
            Node *tmp = new Node;
            tmp->data = data;
            root = tmp;
            return;
        }
        if (data > root->data) {
            return _add(data, root->right);
        } else {
            return _add(data, root->left);
        }
    }
};