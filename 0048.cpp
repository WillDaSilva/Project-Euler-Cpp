#include <iostream>

int main() {

    unsigned long long n = 0;
    unsigned long long modulo = 10000000000;
    for (int a = 1; a <= 1000; ++a) {
        unsigned long long b = a;
        for (int c = 1; c < a; ++c) {
            b *= a;
            b %= modulo;
        }
        n += b;
    }

    std::cout << n % modulo << std::endl;

    return 0;
}
