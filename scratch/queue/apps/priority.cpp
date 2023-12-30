// بسم الله
#include <iostream>

using namespace std;

template <typename T>
struct Queue {
    struct node {
        T data;
        int priority = 0;
        node *next = nullptr;
    };

    node *front = nullptr;
    node *rear = nullptr;

    void enqueue(T data, int priority) {
        node *ptr = new node;
        ptr->data = data;
        ptr->priority = priority;

        // if empty
        if (!front) {
            front = ptr;
            rear = ptr;
            return;
        }
        // if normal add to last to speed it up
        if (!priority) {
            rear->next = ptr;
            rear = rear->next;
            return;
        }
        // if there is one element
        if (!front->next) {
            if (priority <= front->priority) {
                // add last
                rear->next = ptr;        
                rear = rear->next;
            } else {
                // add first
                ptr->next = front;
                front = ptr;
            }
            return;
        }

        node *current = front;
        node *prev = nullptr; 
        while (current) {
            if (priority > current->priority) {
                // add at first 
                if (!prev) {
                    front = ptr;
                    rear = ptr;
                    return;
                }
                // add in middle
                ptr->next = current;
                prev->next = ptr;
                return;
            }
            prev = current;
            current = current->next;
        }
        // add last
        rear->next = ptr;
        rear = rear->next;
        
    }
    void dequeue () {
        node *tmp = front;
        if (!front) 
            return;
        if (!front->next) {
            rear = nullptr;
        }
        front = front->next;
        delete tmp;
    }

    T peak () {
        if (!front) 
            return "null";
        return front->data;
    }
    
    bool is_empty() {
        return (front == nullptr);
    }

};

int main() {
    Queue<string> queue;
    queue.enqueue("sh", 0);
    queue.enqueue("bash", 0);
    queue.enqueue("zsh", 0);
    queue.enqueue("csh", 2);

    cout << "the highest priority is for " << queue.peak() << endl;
}