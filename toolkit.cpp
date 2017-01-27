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
    c = n1 + n2;
    n2 = n1;
    n1 = c;
    return c;
}

primeGenerator::primeGenerator() {
    c = 3;
    first = true;
}

int primeGenerator::next() {
    if (first) {
        first = false;
        primes.push_back(2);
        return 2;
    }
    while (true) {
        prime = true;
        for (int i = 0; i < primes.size() && primes[i]*primes[i] <= c; i++) {
            if (c % primes[i] == 0) {
                prime = false;
                break;
            }
        }
        c += 2;
        if (prime) {
            primes.push_back(c-2);
            return c-2;
        }
    }
}

int prime(int n) {

    primeGenerator pGen;
    for (int i = 0; i < n-1; i++) {pGen.next();}
    return pGen.next();
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
