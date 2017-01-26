#include "toolkit.h"

int main () {

    std::vector<int> primeFactors = getPrimeFactors(600851475143);
    std::cout << primeFactors[primeFactors.size() - 1];

    return 0;
}
