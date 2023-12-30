// بسم الله

template <typename T>
struct Queue {
    struct node {
        T data;
        node *next = nullptr;
    };

    node *front = nullptr;
    node *rear = nullptr;


    void enqueue(T data) {
        node *ptr = new node;
        ptr->data = data;
        
        if (!front) {
            front = ptr;
            rear = ptr;
            return;
        }
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
            return -99;
        return front->data;
    }
    
    bool is_empty() {
        return (front == nullptr);
    }

};