#include <iostream>
#include <cmath>

unsigned long long triangular(int n) {
    return n * (n + 1) / 2;
}

unsigned long long hexagonal(int n) {
    return n * (2 * n - 1);
}

bool isPentagonal(unsigned long long n) {
    return (std::sqrt(24 * n + 1) + 1) / 6 == (unsigned long long)((std::sqrt(24 * n + 1) + 1) / 6);
}

int main() {

    int n = 144;
    while (true) {
        if (isPentagonal(hexagonal(n))) {
            std::cout << hexagonal(n) << std::endl;
            break;
        }
        ++n;
    }

    return 0;
}
