#include "stack.h"


int main() {
    Stack stack;
    stack.top();
    stack.pop();

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