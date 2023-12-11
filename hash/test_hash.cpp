#include <iostream>
#include <fstream>
#include "libs/hash.h"

using namespace std;

int main() {
    Hash table;
    fstream file;

    file.open("data", ios::in);

    string data;
    while(!file.eof()) {
        file >> data;
        table.insert(data);
    }

    // for (char i = 'a'; i < 'z'; i++) {
    //     cout << "Names start with " << i << endl;
    //     table.display_dic(i);
    // }

    table.display_dic('A');
    // table.display_dic('M');
    // table.display_dic('F');
    // table.display_dic('a');
}