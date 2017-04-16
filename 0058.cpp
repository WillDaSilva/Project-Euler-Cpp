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

int main() {

    int a = 1;
    double n = 1;
    double primes = 0;
    int i = 0;
    while (!primes || primes / n > 0.1) {
        ++i;
        for (int j = 0; j < 4; ++j) {
            a += 2*i;
            primes += isPrime(a);
            ++n;
        }
    }

    std::cout << std::sqrt(a) << std::endl;

    return 0;
}
