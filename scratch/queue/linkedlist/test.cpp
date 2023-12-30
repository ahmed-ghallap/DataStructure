// بسم الله
#include <iostream>
#include "help.h"

using namespace std;

int main () {
    Queue<char> queue;
    if (queue.is_empty())
        cout << "Queue is empty\n";
    
    queue.peak();
    queue.dequeue();
    for (int i = 'a'; i <= 'z'; i++) {
        queue.enqueue(i);
    } 

    if (!queue.is_empty())
        cout << "Queue not empty\n";

    for (int i = 'a'; i <= 'z'; i++) {
        cout << queue.peak();
        queue.dequeue();
    } 
    cout << endl;
    if (queue.is_empty())
        cout << "Queue is empty\n";
}