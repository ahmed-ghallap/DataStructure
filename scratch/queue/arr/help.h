// بسم الله
template <typename T>
struct Queue {
    T *arr;
    int front = -1;
    int rear = -1;
    int size;

    Queue(int s) {
        arr = new T[s];
        size = s;
    }

    bool is_empty() {
        return (front == rear and front == -1);
    }

    bool is_full() {
        return ((rear+1)%size == front );
    }

    bool enqueue (T data) {
        if (is_empty()) {
            front = 0;
            rear = 0;
            arr[rear] = data;
            return true;
        }
        if (is_full()) 
            return false;
        rear = (rear + 1) % size;
        arr[rear] = data;
        return true;
    }

    bool dequeue () {
        if (is_empty()) 
            return false;
            
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return true;
    }

    T peak () {
        if (is_empty())
            return -99;
        return arr[front];
    }
};