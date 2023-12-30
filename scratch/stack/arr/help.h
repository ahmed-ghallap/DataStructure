// بسم الله

template <typename T>
struct Stack {
    T *arr;
    int size;
    int top = -1;

    Stack (int s) {
        arr = new T[s];
        size = s;
    }

    bool is_empty () {
        return (top == -1);
    }

    bool is_full () {
        return (top == size);
    }

    T peak () {
        if (is_empty())
            return -99;
        return arr[top];
    }

    void pop () {
        if (is_empty()) 
            return;
        top--;
    }

    bool push (T data) {
        if (is_full()) 
            return false;
        top++; 
        arr[top] = data;
        return true;
    }

    void freeme () {
        delete arr;
    }
};