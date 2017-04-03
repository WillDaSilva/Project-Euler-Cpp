#include <iostream>
#include <cmath>

int sumDivisors(int n) {
    int sum = 1;
    for (int i = 2; i < std::floor(std::sqrt(n)) + 1; ++i) {
        if (n % i == 0) {
            sum += i + n/i;
        }
    }
    return sum;
}

int main() {

    int sum = 0;

    for (int i = 1; i < 10000; ++i) {
        if (i == sumDivisors(sumDivisors(i)) && i != sumDivisors(i)) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
