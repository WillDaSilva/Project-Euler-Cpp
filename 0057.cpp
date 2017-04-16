#include <iostream>
#include "InfInt.h"

int main() {

    InfInt numerator = 3;
    InfInt denominator = 2;

    int n = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (numerator.numberOfDigits() > denominator.numberOfDigits()) {
            ++n;
        }
        InfInt q = denominator;
        denominator += numerator;
        q *= 2;
        numerator += q;
    }

    std::cout << n << std::endl;

    return 0;
}
