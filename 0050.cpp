#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> primeSieve(int n) {
    std::vector<int> result = std::vector<int>();
    if (n < 2) {
        return result;
    }
    std::vector<bool> input(n + 1, true);
    const int limit = (int) (std::floor(std::sqrt(n)) + 1);
    for (int i = 2; i <= limit; i++) {
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

int main() {

    std::vector<int> primes = primeSieve(1000000);
    int largestC = 0;
    int largestP = 0;
    for (int p : primes) {
        int sum = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while (p >= primes[b]) {
            while (sum < p) {
                sum += primes[b];
                ++b;
            }
            while (sum > p) {
                sum -= primes[a];
                ++a;
            }
            if (sum == p) {
                c = b - a;
                break;
            }
        }
        if (c > largestC) {
            largestC = c;
            largestP = p;
        }
    }

    std::cout << largestP << std::endl;

    return 0;
}
