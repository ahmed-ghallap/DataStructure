// بسم الله
#include <iostream>

using namespace std;

template <typename T>
struct doubly_ll {
    struct node {
        T data;
        node *next = nullptr;
        node *prev = nullptr;
    };

    node *head = nullptr;
    node *tail = nullptr;
    int currentSize = 0;

    void addFirst(T data) {
        node *new_ptr = new node;
        new_ptr->data = data;

        if (!head) {
            head = new_ptr;
            tail = new_ptr;
            return;
        }

        head->prev = new_ptr;
        new_ptr->next = head;
        // new_ptr->next->prev = new_ptr;
        head = new_ptr;
        currentSize++; 
    }

    void addLast (T data) {
        if (!head) {
            addFirst(data);
            return;
        }
        node *new_ptr = new node;
        new_ptr->data = data;

        new_ptr->prev = tail;
        tail->next = new_ptr;
        tail = tail->next;
        currentSize++;
    }

    bool add_v_n1_n2(T data, T n1, T n2) {
        if (!head || !head->next) 
            return false;

        node *prev = head;
        node *current = head->next;
        while (current) {
            if (current->data == n2 && prev->data == n1) {
                node *new_ptr = new node;
                new_ptr->data = data;

                prev->next = new_ptr;
                new_ptr->next = current;

                current->prev = new_ptr;
                new_ptr->prev = prev;
                currentSize++;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    bool removeFirst() {
        if (!head) 
            return false;

        node *deleted = head;
        if (head == tail) {
            tail = nullptr;
        }
        head = head->next;
        if (head)
            head->prev = nullptr;
        currentSize--;
        delete deleted;
        return true;
    }

    bool removeLast() {
        if (head == tail || !head) 
            return removeFirst();
        
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        currentSize--;
        return true;
    }

    bool remove(T data) {
        if (!head) 
            return false;

        if (head->data == data) 
            return removeFirst();

        if (tail->data == data) 
            return removeLast();

        for (node *current = head; current; current=current->next) {
            if (current->data == data) {
                node *prev = current->prev;
                node *next = current->next;

                prev->next = next;
                next->prev = prev;
                delete current;
                currentSize--;
                return true;
            }
        }
        return false;
    }

    void display_front () {
        if (head) 
            cout << "[ ";
        for (node *tmp = head; tmp; tmp=tmp->next) {
            cout << tmp->data << ' ';
        }
        if (head) {
            cout << " ]\n";
        }
    }
    void display_reverse () {
        if (tail) 
            cout << "[ ";
        for (node *tmp = tail; tmp; tmp=tmp->prev) {
            cout << tmp->data << ' ';
        }
        if (tail) {
            cout << " ]\n";
        }    
    }

};
