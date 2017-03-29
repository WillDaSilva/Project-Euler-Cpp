#include <iostream>
#include "InfInt.h"

InfInt factorial(InfInt n) {
    InfInt result = 1;
    for (InfInt i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {

    int sum = 0;

    for (InfInt n = 3; n < 100000; n++) {
        int factorialDigitSum = 0;
        for (int i = 0; i < n.numberOfDigits(); i++) {
            factorialDigitSum += factorial(n.digitAt(i)).toInt();
        }
        if (n == factorialDigitSum) {
            sum += factorialDigitSum;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
