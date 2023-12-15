#include <iostream>
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

struct node {
    string val;
    node *next = NULL;
};

struct List {
        node *head = NULL;
        node *tail = NULL;
        int size = 0;
        
        void addFirst(string x) {
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

        void display(void) {
            if (head == nullptr) {
                std::cout << "The list is empty.\n";
                return;
            }

            node *tmp = head;
            std::cout << '[';
            for (int i = 0; i < 1000 && tmp; i++) {
                std::cout << tmp->val << " ";
                tmp = tmp->next;
            }
                std::cout <<"]\n";
        }
        
        bool contain(string s ) {
            node *tmp = head;
            while (tmp != NULL) {
                if (tmp->val == s) {
                    return true;
                }
                tmp = tmp->next;
            }
            return false;
        }

        int len(void) {
            return size;
        }
};


struct Hash {
    List arr[26];
    int size = 26;  

    int elem_count() {
        int tmp = 0;
        for (int i = 0; i < size; i++) {
            tmp += arr[i].len();
        }
        return tmp;
    }

    int hash_fun(string s) {
        return (int) tolower(s[0]) % size;
    }

    void insert(string s) {
        int index = hash_fun(s);
        arr[index].addFirst(s);
    }

    void display_dict(char key) {
        int index = tolower(key) % size;
        arr[index].display(); 
    }

    bool contain(string s) {
        int index = hash_fun(s);
        return arr[index].contain(s);
    }
};

int main() {
    Hash table;
    // fstream file;

    // file.open("data", ios::in);

    // string data;
    // while(!file.eof()) {
    //     file >> data;
    //     table.insert(data);
    // }

    // for (char i = 'a'; i < 'z'; i++) {
    //     cout << "Names start with " << i << endl;
    //     table.display_dic(i);
    // }

    table.insert("Ahmed");
    table.insert("ahmed");
    table.insert("Mohamed");
    table.insert("Moumen");
    table.insert("Mourad");
    table.insert("Abd-Allah");
    table.insert("Foud");

    table.display_dict('A');
    table.display_dict('M');
    table.display_dict('f');
    cout << "elem coutn si " << table.elem_count() << endl;
    if (table.contain("ahmed")) {
        cout << "Ahmed is there\n";
    }
}