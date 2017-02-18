#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> getPrimeFactors(unsigned long long n){
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

int main () {

    std::vector<int> primeFactors = getPrimeFactors(600851475143);
    std::cout << primeFactors[primeFactors.size() - 1];

    return 0;
}
