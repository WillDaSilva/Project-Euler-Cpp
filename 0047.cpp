#include <iostream>
#include <unordered_set>

std::unordered_set<int> getDistinctPrimeFactors(int n) {
    std::unordered_set<int> distinctPrimeFactors;
    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                distinctPrimeFactors.insert(i);
                n /= i;
                --i;
            }
        }
    }
    return distinctPrimeFactors;
}

int main() {

    int numConsecutiveValidValues = 0;
    int n = 0;
    while (numConsecutiveValidValues != 4) {
        if (getDistinctPrimeFactors(n).size() == 4) {
            ++numConsecutiveValidValues;
        }
        else {
            numConsecutiveValidValues = 0;
        }
        ++n;
    }

    std::cout << n - 4 << std::endl;

    return 0;
}
