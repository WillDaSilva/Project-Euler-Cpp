#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 0) {
        return false;
    }
    else if (n == 2) {
        return true;
    }
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int productAB;
    int largestN = 0;

    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n = 0;
            bool consecutive = true;
            while (consecutive) {
                ++n;
                if (!isPrime(n*n + a*n + b)) {
                    consecutive = false;
                    if (n > largestN) {
                        largestN = n;
                        productAB = a * b;
                    }
                }
            }
        }
    }

    std::cout << productAB << std::endl;

    return 0;
}
