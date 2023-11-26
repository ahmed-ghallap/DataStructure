// بسم الله
#include <iostream>

typedef int data;
// Start liked list defnation
struct node {
    data val;
    node *next = NULL;
};

int datacmp(data d1, data d2) {
    if (d1 == d2 ) {
        return 0;
    }
    if (d1 > d2) {
        return 1;
    }
    return -1;
}

class List {
    private:
        node *head = NULL;
        node *tail = NULL;
        int size = 0;
    public:
    data peakFirst(void) {
        if (head == NULL) {
            std::cout << "empty list\n";
            return 0;
        }
        return head->val;
    }
    data peakLast(void) {
        // node *tmp = head;
        // if (head == NULL) 
        //     return NULL;
        // while(tmp->next != NULL) {
        //     tmp = tmp->next;
        // } 
        // return tmp->val;
        if (tail == NULL) {
            std::cout << "empty list\n";
            return 0;
        }
        return tail->val;
    }

    void addFirst(data x) {
        node *newNode =  new node;
        newNode->val = x;
        newNode->next = head;
        // *newNode = {x, head};
        head = newNode;
        if (newNode->next == NULL) {
        // اذا كانت فارغة فإن اول عنصر هو ايضا اخر عنصر
            tail = head;
        }
        size++;
    }

    void addLast(data x) {
        node *newNode =  new node;
        newNode->val = x;
        // هي بالفعل تساوي null
        // newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = head;
            size++;
            return;
        }
        tail->next = newNode;
        size++;
    }

    bool contain(data x) {
        node *tmp = head;
        while ( tmp != NULL)
        {
            if (datacmp(x, tmp->val) == 0) {
                return true;
            }
        }
        return false;
        
    }

    data remove(data x) {
        node *current, *previuos;
        current = head; previuos = NULL;
        while (current != NULL) {
            if (datacmp(x, current->val) == 0) {
               if (head == tail) {
                    // عنصر واخد
                    return removeFirst();
               } 
               if (current == tail) {
                    return removeLast();
               }
               previuos->next = current->next;
               data tmp = current->val;
               delete current;
               size--;
               return tmp;
            }
            previuos = current;
            current = current->next;
        }
        std::cout << "Object Not Found; Error at removing it\n";
        return 0;
    }

    data removeFirst() {
        if (head == NULL) {
            return 0;
        }
        node *tmp = head;
        head = head->next;
        if (head == NULL) {
            // اذا اصبحت القئمة فارغة, اعد ضبطها
            tail = NULL;
        }
        data tmpData = tmp->val;
        delete tmp;
        size--;
        return tmpData;
    }

    data removeLast() {
        // لو كان فارغ
        if (head == NULL) {
            std::cout << "emtyp list\n";
            return 0;
        }
        //  اذا كان عنصرا يتيما
        // if (head == tail) {
        if (head->next == NULL) {
            return removeFirst();
            // data tmp = head->val; 
            // delete head;
            // size--;
            // head = NULL; tail = NULL;
            // tmp;
        }

        node *current, *previous;
        current = head;
        previous = nullptr;
        // while (current->next != nullptr)
        while (current != tail)
        {
            previous = current;
            current = current->next; 
        }
        tail = previous;
        tail->next = nullptr;
        
        data tmpdata = current->val;
        delete current;
        size--;
        return tmpdata;
    }
      
        void display(void) {
            if (head == nullptr) {
                std::cout << "The list is empty.\n";
                return;
            }

            node *tmp = head;
            std::cout << '[';
            while (tmp != NULL) {
                std::cout << tmp->val << " ";
                tmp = tmp->next;
            }
            std::cout <<"]\n";
        }

    // char *str(void) {
    //     data *s = new data[size+1];
    //     node *tmp = head;
    //     int i;
    //     for (i = 0; i < size && tmp != NULL; i++) {
    //         s[i] = tmp->val;
    //         tmp = tmp->next;
    //     }
    //     s[i] = '\0';
    //     return s;
    // }
    int len(void) {
        return size;
    }

};
