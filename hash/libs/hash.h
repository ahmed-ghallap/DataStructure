#include <iostream>
#include <cctype>

#include "newlist.h"

using namespace std;

struct Hash {
    List arr[26];
    int size = 26;

    int hash_fun(string s) {
        return (int) tolower(s[0]) % size;
    }

    void insert(string s) {
        int index = hash_fun(s);
        arr[index].addFirst(s);
    }

    void display_dic(char key) {
        int index = tolower(key) % size;
        arr[index].display(); 
    }
};
