#include <iostream>
#include <set>
#include "InfInt.h"

int main() {

    std::set<InfInt> results;
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            InfInt c = 1;
            for (int i = 0; i < b; i++) {
                c *= a;
            }
            results.insert(c);
        }
    }

    std::cout << results.size() << std::endl;

    return 0;
}
