#include "toolkit.h"

fibonacciGenerator::fibonacciGenerator() {
    n1 = 0;
    n2 = 1;
    first = false;
}

int fibonacciGenerator::next() {
    if (!first) {
        first = true;
        return 0;
    }
    r = n1 + n2;
    n2 = n1;
    n1 = r;
    return r;
}

template <typename T>
std::vector<int> getPrimeFactors(T n){
    std::vector<int> primeFactors;
    while (n % 2 == 0) {
        primeFactors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i < std::ceil(std::sqrt(n)); i += 2) {
        while (n % i == 0) {
            primeFactors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        primeFactors.push_back(n);
    }
    return primeFactors;
}

void getPrimeFactors_templateInstantiationFunction() {
    getPrimeFactors((long long)0);
}
