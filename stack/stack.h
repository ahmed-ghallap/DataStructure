#include <iostream>

using namespace std;

struct node {
    char data;
    node *next = nullptr;
};

struct Stack {
    node *head = nullptr;
    int currentSize = 0;

    void push(int x) {
        node *new_node = new node;
        new_node->data = x;
        // being empty does not matter
        new_node->next = head;
        head = new_node;
        currentSize++;
    }

    int top() {
        if (head == nullptr) {
            cout << "Stack is empty\n";
            return -99;
        }
        return head->data;
    }
    
    int pop() {
        if (head == nullptr) {
            cout << "Stack is empty\n";
            return -99;
        }
        node *tmp = head;
        head = head->next;
        
        int Data = tmp->data;
        delete tmp;
        return Data;
    }

    bool is_empty() {
        return (head == nullptr);
    }
    
    int size() {
        return currentSize;
    }

    void reverse(string w) {
        for (int i = 0; i < w.length(); i++) {
            push(w[i]);
        }
        for (int i = 0; i < w.length(); i++) {
            cout << (char) pop() << " ";
        }
        cout << endl;
    }
};

bool match(char c1, char c2) {
    switch (c1) {
        case '{':
            return (c2 == '}');
        case '[':
            return (c2 == ']');
        case '(':
            return (c2 == ')');
    }
    return false;
}

bool is_open_prant(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool is_close_prant(char c) {
    return (c == ')' || c == '}' || c == ']');
}

bool check_prant(string w) {
    Stack stack;
    for (int i = 0; i < w.length(); i++) {
        if (is_open_prant(w[i])) {
            stack.push(w[i]);
        } else if (is_close_prant(w[i])) {
            int popped = stack.pop();
            if (popped == -99) 
                return false;
            if (!match(popped, w[i]))
                return false;
        }
    }
    return stack.is_empty();
}