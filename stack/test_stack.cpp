#include "stack.h"


int main() {
    Stack stack;
    if (check_prant("(){}")) {
        cout << "work well\n";
    } else {
        cout << "Not work well\n";
    }

    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }

    for (int i = 9; i >= 0; i--) {
        int poped = stack.pop();
        if (poped != i) {
            cout << "Error at push or pop\n";
            cout << poped << " " << i << endl;
        }
    }
}