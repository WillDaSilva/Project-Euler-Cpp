#include <iostream>

int main() {

    int triangularNumber = 1;
    int incrementer = 1;
    int numDivisors = 0;

    while (numDivisors <= 500) {

        numDivisors = 0;
        incrementer += 1;
        triangularNumber += incrementer;

        for (int i = 1; i*i <= triangularNumber; ++i) {
            if (triangularNumber % i == 0) {
                numDivisors += 2;
            }
        }
    }

    std::cout << triangularNumber << std::endl;

    return 0;
}
