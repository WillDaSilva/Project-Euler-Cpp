#include <iostream>
#include "InfInt.h"

int main() {

    InfInt a = 0;
    InfInt b = 1;
    InfInt c;
    int index = 0;

    while (a.numberOfDigits() < 1000) {
        c = a;
        a = b;
        b = c + b;
        ++index;
    }

    std::cout << index << std::endl;

    return 0;
}
