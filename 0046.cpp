#include <iostream>
#include <cmath>
#include <vector>

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

std::vector<int> primes;

bool check(int n) {
    for (int p : primes) {
        int q = 1;
        while (n >= p + 2 * q * q) {
            if (n == p + 2 * q * q) {
                return true;
            }
            ++q;
        }
    }
    return false;
}

int main() {

    int n = 2;
    while (true) {
        if (isPrime(n)) {
            primes.push_back(n);
        }
        else if (n % 2 != 0 && !check(n)) {
            break;
        }
        ++n;
    }
    std::cout << n << std::endl;

    return 0;
}
