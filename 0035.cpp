#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

int getNumDigits(int n) {
    int numDigits = 0;
    while (n > 0) {
        ++numDigits;
        n /= 10;
    }
    return numDigits;
}

std::vector<int> primeSieve(int n) {
    std::vector<int> result = std::vector<int>();
    if (n < 2) {
        return result;
    }
    std::vector<bool> input(n + 1, true);
    const int limit = (int) (std::floor(std::sqrt(n)) + 1);
    for (int i = 2; i <= limit; ++i) {
        if (!input[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            input[j] = false;
        }
    }
    result.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (input[i]) {
            result.push_back(i);
        }
    }
    return result;
}

bool isMadeOf1379(int n) {
    while (n > 0) {
        if (n % 10 != 1 && n % 10 != 3 && n % 10 != 7 && n % 10 != 9) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {

    std::vector<int> primes = primeSieve(1000000);
    std::unordered_set<int> circularPrimes;

    for (int p : primes) {
        if (isMadeOf1379(p)) {
            bool isCircularPrime = true;
            int numDigits = getNumDigits(p);
            for (int i = 0; i < numDigits - 1; ++i) {
                p = (p / 10) + ((p % 10) * std::pow(10, numDigits - 1));
                if (!std::binary_search(primes.begin(), primes.end(), p)) {
                    isCircularPrime = false;
                    break;
                }
            }
            if (isCircularPrime) {
                for (int i = 0; i < numDigits; ++i) {
                    p = p / 10 + (p % 10) * std::pow(10, numDigits - 1);
                    circularPrimes.insert(p);
                }
            }
        }
    }

    std::cout << circularPrimes.size() + 2 << std::endl;

    return 0;
}
