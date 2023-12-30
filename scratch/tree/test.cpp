// بسم الله

#include "help.h"

int main () {
    Tree<int> tree;
    // for (int i = 3; i < 10; i++) {
    //     tree._add(i, tree.root);
    // }
    // tree._add(3, tree.root);
    tree.add(3);
    cout << tree.root->data << endl;
    // tree.inorder();
}