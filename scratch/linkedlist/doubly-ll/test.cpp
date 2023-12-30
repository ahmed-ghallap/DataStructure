// بسم الله
#include "help.h"

int main () {
    doubly_ll<char> moma;

    for (int i = 'a'; i <= 'z'; i++) {
        moma.addLast(i);
    }

    // moma.add_v_n1_n2('5', 'c', 'd');

    moma.display_front();
    moma.remove('z');
    moma.display_front();
    
}