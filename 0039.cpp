#include <iostream>
#include <cmath>

int main() {

    int optimalP = 0;
    int largestNumSolutions = 0;
    for (int p = 3; p <= 1000; p++) {
        int numSolutions = 0;
        int a = 1;
        while (a < p / 4) {
            int b = 1;
            while (b < (p - a) / 2) {
                if (p == a + b + std::sqrt(a * a + b * b)) {
                    ++numSolutions;
                }
                ++b;
            }
            ++a;
        }
        if (numSolutions > largestNumSolutions) {
            largestNumSolutions = numSolutions;
            optimalP = p;
        }
    }

    std::cout << optimalP << std::endl;

    return 0;
}
