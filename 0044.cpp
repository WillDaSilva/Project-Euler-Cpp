#include <iostream>
#include <cmath>

unsigned long pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}

bool isPentagonal(unsigned long n) {
    return (std::sqrt(24 * n + 1) + 1) / 6 == (unsigned long)((std::sqrt(24 * n + 1) + 1) / 6);
}

int main() {

    for (int a = 1; a < 3000; a++) {
        for (int b = a + 1; b < 3000; b++) {
            if (isPentagonal(pentagonal(b) - pentagonal(a)) && isPentagonal(pentagonal(b) + pentagonal(a))) {
                std::cout << pentagonal(b) - pentagonal(a) << std::endl;
                return 0;
            }
        }
    }

    return 0;
}
