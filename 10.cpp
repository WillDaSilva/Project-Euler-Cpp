#include "toolkit.h"

int main() {

    primeGenerator pGen;
    long long sum = 0;
    int prime;

    while (true) {
        prime = pGen.next();
        if (prime >= 2000000) {
            break;
        }
        sum += prime;
    }

    std::cout << sum << std::endl;

    return 0;
}
