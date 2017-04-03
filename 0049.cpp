#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    else if (n == 2) {
        return true;
    }
    else if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPermutation(int a, int b) {
    int c[10] = {0};
    while (a > 0) {
        ++c[a % 10];
        a /=10;
    }
    while (b > 0) {
        --c[b % 10];
        b /= 10;
    }
    bool permutation = true;
    for (int i = 0; i < 10; ++i) {
        permutation &= !c[i];
    }
    return permutation;
}

int main() {

    for (int n = 1000; n < 3340; ++n) {
        if (isPrime(n) && isPrime(n + 3330) && isPrime(n + 2 * 3330) && isPermutation(n, n + 3330) && isPermutation(n , n + 2 * 3330) && n != 1487) {
            std::cout << std::to_string(n) + std::to_string(n + 3330) + std::to_string(n + 2 * 3330) << std::endl;
            break;
        }
    }

    return 0;
}
