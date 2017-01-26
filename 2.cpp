#include <iostream>
#include "toolkit.h"

int main() {

    fibonacciGenerator fib;
    int next = 0;
    int sum = 0;

    while (next < 4000000) {
        next = fib.next();
        if (next % 2 == 0) {
            sum += next;
        }
    }

    std::cout << sum;

    return 0;
}
