#include <iostream>


template <typename T>
struct single_ll {
    private:
        struct node {
            T data;
            node *next = nullptr;
        };
        
        node *head = nullptr;
        int currentSize = 0;
    public:

        void display() {
            node *tmp = head;
            if (head) {
                std::cout << "[ ";
            }
            while (tmp) {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
            if (head) {
                std::cout << "]\n";
            }
        }

        void addFirst(T data) {
            node *new_element = new node;
            new_element->data = data;
            new_element->next = head;
            head = new_element;
            currentSize++;
        }

        void addLast(T data) {
            node *tmp = head;
            node * new_element = new node;
            new_element->data = data;
            new_element->next = NULL;

            if (!head) {
                head = new_element;
                return;
            }
            while (tmp->next) {
                tmp = tmp->next;
            }

            tmp->next = new_element;
            currentSize++;
        }

        bool add_v_n1_n2(T data ,T n1, T n2) {
            node *new_node = new node;
            new_node->data = data;

            if (!head || !head->next) {
                return false;
            }

            node *previuse = head;
            node *current = head->next;
            while (current) {
                if (previuse->data == n1 && current->data == n2) {
                    previuse->next = new_node;
                    new_node->next = current;
                    currentSize++;
                    return true;
                }
                previuse = current;
                current = current->next;    
            }
            return false;
        }

        bool removeFirst() {
            if (!head) {
                std::cout << "Nothing to delete\n";
                return false;
            }
            node *removed = head;
            head = head->next;

            delete removed;
            currentSize--;
            return true;
        }

        bool removeLast() {
            if (!head || !head->next) {
                return removeFirst();
            }
            node *previuse = head;
            node *current = head->next;
            while (current->next) {
                previuse = current;
                current = current->next;
            }
            previuse->next = nullptr;
            delete current;
            currentSize--;
            return true;

        }

        bool remove(T data) {
            node *previuse = head;
            node *current = head;
            if (!head)
                return false;
            if (head->data == data) 
                return removeFirst();

            while (current) {
                if (current->data == data) {
                    previuse->next = current->next;
                    delete current;
                    currentSize--;
                    return true;
                }
                previuse = current;
                current = current->next;
            }
            return false;
        }

};