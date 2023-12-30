#include "help.h"

int main() {
    single_ll <char> lola;
    for (int i = 'a'; i < 'z'; i++) {
        lola.addLast(i);
    }
    // for (int i = 'a'; i <= 'z'; i++) 
    //     lola.removeFirst();

    std::cout << lola.removeFirst() << '\n';
    std::cout << lola.removeLast() << '\n';
    lola.remove('b');
    lola.add_v_n1_n2('5', 'c', 'd');

    lola.display();

}