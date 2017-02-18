#include <iostream>
#include <cmath>

int main() {

    unsigned long long sumOfSquares = 0;
    unsigned long long squareOfSums = 0;

    for (int i = 1; i < 101; i++) {
        sumOfSquares += (int)std::floor(std::pow(i, 2));
        squareOfSums += i;
    }

    std::cout << (unsigned long long)std::floor(std::pow(squareOfSums, 2)) - sumOfSquares << std::endl;

    return 0;
}
