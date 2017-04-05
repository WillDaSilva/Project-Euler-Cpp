#include <iostream>
#include <cmath>
#include "InfInt.h"

int main() {

    int maxDigitSum = 0;
    for (int a = 90; a < 100; ++a) {
        for (int b = 90; b < 100; ++b) {
            InfInt n = 1;
            for (int c = 0; c < b; ++c) {
                n *= a;
            }
            int digitSum = 0;
            for (int i = 0; i < n.numberOfDigits(); ++i) {
                digitSum += n.digitAt(i);
            }
            if (digitSum > maxDigitSum) {
                maxDigitSum = digitSum;
            }
        }
    }

    std::cout << maxDigitSum << std::endl;

    return 0;
}
