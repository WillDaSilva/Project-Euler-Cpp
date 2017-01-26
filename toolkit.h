#pragma once
#include <cmath>
#include <vector>
#include <iostream>

class fibonacciGenerator {

    int n1;     // One term back
    int n2;     // Two terms back
    int r;      // current term
    bool first; // First value has been generated
    bool second;// Second value has been generated

public:
    fibonacciGenerator();
    int next();
};

template <typename T>
std::vector<int> getPrimeFactors(T n);

void getPrimeFactors_templateInstantiationFunction();
