#pragma once
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class fibonacciGenerator {

    int n1;     // One term back
    int n2;     // Two terms back
    int c;      // current term
    bool first; // First value has been generated
    bool second;// Second value has been generated

public:
    fibonacciGenerator();
    int next();
};

class primeGenerator {

    int c; // current term
    bool prime;
    bool first;
    std::vector<int> primes;

public:
    primeGenerator();
    int next();
};

int prime(int);

template <typename T>
std::vector<int> getPrimeFactors(T);

void getPrimeFactors_templateInstantiationFunction();

unsigned long long int factorial (unsigned int n);
