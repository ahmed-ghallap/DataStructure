// بسم الله
#include <iostream>

using namespace std;

struct node {
    char data;
    int priority = 0;
    node *next = NULL;

};

struct queue {
    node *front = NULL;
    node *rear = NULL;

    bool is_empty() {
        return (front == NULL);
    }

    void enqueue(char val, int p) {
        node *new_node = new node;
        new_node->data = val;
        new_node->priority = p;
        new_node->next = NULL;
        
        // اذا كانت فارغة
        if (is_empty()) {
            front = new_node;
            rear = front;
            return;
        }
        // الوضع الطبيعي
        // اذا كانت الاولويه اصغر من او يساوي اخر عنصر
        if (rear->priority >= p ) {
            rear->next = new_node;
            rear = rear->next;
            return;
        }


        // اذا كان موضعه في البداية
        if (p > front->priority) {
            new_node->next = front;
            front = new_node;
            return;
        }

    

        node *tmp = front;
        while (!(p > tmp->next->priority)) {
            // اذا وصلت الي النهاية
            if (tmp->next == NULL) {
                tmp->next = new_node;
                return;
            }
            tmp = tmp->next;
        }
        new_node->next = tmp->next;
        tmp->next = new_node;
    }

    void display() {
        node *tmp = front;
        while (tmp) {
            cout << "( " << tmp->data << ',' << tmp->priority  << ")" << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main() {
    queue koka;
    koka.enqueue('a', 5);
    koka.enqueue('B', 5);
    koka.enqueue('V', 3);
    koka.enqueue('G', 10);
    koka.enqueue('G', 7);
    
    koka.display();
}

//  الحمد لله