// بسم الله
#include <iostream>
#include "../linkedlist/help.h"



using namespace std;

bool match (char open, char close) {
    switch (open) {
        case '(':
            if (close == ')')
                return true;

        case '[':
            if (close == ']')
                return true;
    }
    return false;
}

int main () {
    Stack <char> stack;
    string s = "(5+3[23.3-(1+5)1])";
    s = "(5+3]23.3-(1+5)1])";
    for (auto i : s) {
        if (i == '(' or i == '[') 
            stack.push(i);
        if (i == ')' or i == ']') {
            if (match(stack.peak(), i)) {
                stack.pop();
            } else {
                cout << "Error\n";
            }
            
        }
    }
}