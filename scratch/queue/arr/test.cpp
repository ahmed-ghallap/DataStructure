// بسم الله

#include "help.h"
#include <iostream>

using namespace std;

int main () {
    Queue<int> queue(10);
    for (int i = 0; i < 20; i++) {
        queue.enqueue(i);
    }

    // cout << "fornt: " << queue.front << " rear: " << queue.rear << endl;
    // cout << queue.arr[1] << endl;;

    for (int i = 0; i < 20; i++) {
        int tmp = queue.peak();
        if (tmp == -99) 
            return 0;
        else 
            cout << tmp << endl;
        queue.dequeue();
    }

    
}