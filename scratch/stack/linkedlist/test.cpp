//بسم الله 
#include <iostream>
#include "help.h"

using namespace std;

int main () {
    Stack<char> zoza;
    for (int i = 'a'; i <= 'z'; i++) {
        zoza.push(i);
        zoza.pop();
    } 
}