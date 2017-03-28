#include <iostream>
#include <cmath>

int main() {

    int sum = 0;
    int n = 1;
    int limit = 6 * std::pow(9, 5);
    while (n < limit) {
        ++n;
        int digitSum = 0;
        int q = n;
        while (q != 0) {
            digitSum += std::pow(q % 10, 5);
            q /= 10;
        }
        if (digitSum == n) {
            sum += n;
        }
    }

    std::cout << sum << std::endl;

    return 0;

}
