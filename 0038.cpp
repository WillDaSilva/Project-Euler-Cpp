#include <iostream>

bool isPandigital_9(long long n) {
    int results = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0) {
            return false;
        }
        results |= 1 << (digit - 1);
        n /= 10;
    }
    return results == 511;
}

long long concatenateNumbers(long long a, long long b) {
    long long c = 1;
    while (c <= b) {
        c *= 10;
    }
    return (a * c) + b;
}

int main() {

    long long max = 0;
    for (int i = 1; i < 10000; ++i) {
        long long concatenatedProduct = i;
        int n = 2;
        while (concatenatedProduct < 100000000) {
            concatenatedProduct = concatenateNumbers(concatenatedProduct, i * n);
        }
        if (isPandigital_9(concatenatedProduct) && concatenatedProduct > max) {
            max = concatenatedProduct;
        }
    }

    std::cout << max << std::endl;

    return 0;
}
