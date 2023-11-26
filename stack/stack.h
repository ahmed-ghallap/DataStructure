#include <iostream>

using namespace std;

struct node {
    int data;
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
};

