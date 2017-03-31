#include <iostream>
#include <string>
#include <algorithm>

int main() {

    std::string digits = "0123456789";
    unsigned long long sum = 0;

    do {
        int any =
            std::stoull(std::string(digits, 1, 3)) % 2 +
            std::stoull(std::string(digits, 2, 3)) % 3 +
            std::stoull(std::string(digits, 3, 3)) % 5 +
            std::stoull(std::string(digits, 4, 3)) % 7 +
            std::stoull(std::string(digits, 5, 3)) % 11 +
            std::stoull(std::string(digits, 6, 3)) % 13 +
            std::stoull(std::string(digits, 7, 3)) % 17;
        if (!any) {
            sum += std::stoull(digits);
        }
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << sum << std::endl;

    return 0;
}
