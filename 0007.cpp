#include <iostream>
#include <vector>
#include <cmath>

class primeGenerator {

    int c; // current term
    bool prime;
    bool first;
    std::vector<int> primes;

public:

    primeGenerator() {
        c = 3;
        first = true;
    }

    int next() {
        if (first) {
            first = false;
            primes.push_back(2);
            return 2;
        }
        while (true) {
            prime = true;
            for (int i = 0; i < primes.size() && primes[i] <= std::floor(std::sqrt(c)) + 1; i++) {
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
};


int prime(int n) {

    primeGenerator pGen;
    for (int i = 0; i < n-1; i++) {pGen.next();}
    return pGen.next();
}

int main() {

    std::cout << prime(10001) << std::endl;

    return 0;
}
