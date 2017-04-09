#include <iostream>
#include <vector>
#include "InfInt.h"

int main() {

    std::vector<InfInt> numerators;
    numerators.push_back(1);
    numerators.push_back(3);

    std::vector<InfInt> denominators;
    denominators.push_back(1);
    denominators.push_back(2);

    int n = 0;
    for (int i = 2; i < 1000; ++i) {
        numerators.push_back(InfInt(2) * numerators[i - 1] + numerators[i - 2]);
        denominators.push_back(InfInt(2) * denominators[i - 1] + denominators[i - 2]);
        if (numerators[i].numberOfDigits() > denominators[i].numberOfDigits()) {
            ++n;
        }
    }

    std::cout << n << std::endl;

    return 0;
}
