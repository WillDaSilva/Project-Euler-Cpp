#include <iostream>
#include <unordered_set>

long long concatenateInts(int a, int b) {
    long long c = 1;
    while (c <= b) {
        c *= 10;
    }
    return (a * c) + b;
}

bool isPandigital_9(int n) {
    int results = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0) {
            return false;
        }
        results |= 1 << (digit - 1);
        n /= 10;
    }
    return results == 0x1ff;
}

bool checkValue(int a, int b) {
    long long n = concatenateInts(concatenateInts(a, b), a * b);
    return n > 123456789 && n < 1000000000 && isPandigital_9(n);
}

int main() {

    std::unordered_set<long long> pandigitals;

    // NN * NNN = NNNN
    for (int a = 10; a < 100; a++) {
        for (int b = 100; b < 1000; b++) {
            if (checkValue(a, b)) {
                pandigitals.insert(a * b);
            }
        }
    }

    // N * NNNN = NNNN
    for (int a = 1; a < 10; a++) {
        for (int b = 1000; b < 10000; b++) {
            if (checkValue(a, b)) {
                pandigitals.insert(a * b);
            }
        }
    }

    int sum = 0;
    for (int i : pandigitals) {
        sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}
