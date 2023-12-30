// بسم الله
#include "help.h"
#include <iostream>

using namespace std;

int main () {
    Stack<int> koka(10);
    

    for (int i = 0; i < 10; i++) {
        koka.push(i);
    }

    for (int i = 0; i < 100; i++) {
        cout << koka.peak() << endl;
        koka.pop();
    }
    koka.freeme();
}
