// بسم الله

template <typename T>
struct Stack {
    struct node {
        T data;
        node *next;
    };

    node *top = nullptr;

    bool is_empty () {
        return (!top);
    }

    void push (T data) {
        node *ptr = new node;
        ptr->data = data;
        ptr->next = top;
        top = ptr;
    }

    T peak () {
        if (is_empty()) 
            return -99;
        return top->data;
    }

    bool pop () {
        if (is_empty()) 
            return false;
        node *deleted = top;
        top = top->next;
        delete deleted;
        return true;
    }

};