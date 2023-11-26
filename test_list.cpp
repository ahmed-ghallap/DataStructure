// بسم الله
#include "newlist.h"
#include <stdlib.h>

using namespace std;

int N = 10;

bool test_addFirst_len();
bool test_addLast_len();
bool test_addFirst_removeFirst();
// The program will crash if you insert (0);

int main(void) {
    system("clear");
    if (!test_addFirst_len())
        cout << "Erro at addFirst Or len\n" ;
    if (!test_addLast_len())
        cout << "Erro at addFirst Or len\n" ;
    if (!test_addFirst_removeFirst()) {
        cout << "Erro at addFirst Or removeFirst\n" ;
    }

}


bool test_addFirst_len() {
    List sosa;
    for (int i = 1; i < N; i++) {
        // تدشين القئمة
        sosa.addFirst(i);
    }
    sosa.display();
    if (sosa.len() == N-1) {
        //  اختبار len
        return true;
    }
    return false;
}

bool test_addFirst_removeFirst() {
    List sosa;
    for (int i = 1; i < N; i++) {
        sosa.addFirst(i);
    }

    for (int i = N-1; i >= 1; i--) {
        int removed = sosa.removeFirst();
        if (!removed == i) {
            return false;
        }
    }
    return true;

}
bool test_addFirst_removeLast() {
    List sosa;
    for (int i = 1; i < N; i++) {
        sosa.addFirst(i);
    }

    for (int i = 1; i < N; i++) {
        int removed = sosa.removeLast();
        if (!removed == i) {
            return false;
        }
    }
    return true;

}


bool test_addLast_len() {
    List sosa;
    for (int i = 1; i < N; i++) {
        // تدشين القئمة
        sosa.addLast(i);
    }
    if (sosa.len() == N-1) {
        //  اختبار len
        return true;
    }
    return false;
}

// bool test_addLast_removeLast() {

// }

