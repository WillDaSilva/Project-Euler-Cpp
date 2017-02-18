#include <iostream>

class fibonacciGenerator {

    int n1;     // One term back
    int n2;     // Two terms back
    int c;      // current term
    bool first; // First value has been generated
    bool second;// Second value has been generated

public:

    fibonacciGenerator() {
        n1 = 0;
        n2 = 1;
        first = false;
    }

    int next() {
        if (!first) {
            first = true;
            return 0;
        }
        c = n1 + n2;
        n2 = n1;
        n1 = c;
        return c;
    }
};



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
