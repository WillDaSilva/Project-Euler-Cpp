#include <iostream>
#include <cmath>

int getNumDigits(int n) {
    int numDigits = 0;
    while (n > 0) {
        ++numDigits;
        n /= 10;
    }
    return numDigits;
}

int getLeftmostDigit(int n) {
    int leftmostDigit = n;
    while (true) {
        if (leftmostDigit % 10 == leftmostDigit) {
            return leftmostDigit;
        }
        leftmostDigit /= 10;
    }
    return 0;
}

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

bool isTruncatablePrimeRight(int n) {
    while (n > 0) {
        if (!isPrime(n)) {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool isTruncatablePrimeLeft(int n) {
    while (n > 0) {
        if (!isPrime(n)) {
            return false;
        }
        n -= getLeftmostDigit(n) * std::pow(10, getNumDigits(n) - 1);
    }
    return true;
}

bool isTruncatablePrime(int n) {
    return isTruncatablePrimeLeft(n) && isTruncatablePrimeRight(n);
}

int main() {

    int sum = 0;
    int numFound = 0;
    int n = 10;
    while (numFound < 11) {
        if (isTruncatablePrime(n)) {
            sum += n;
            ++numFound;
        }
        ++n;
    }

    std::cout << sum << std::endl;

    return 0;
}
