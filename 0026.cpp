#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> primeSieve(int n) {
    std::vector<int> result = std::vector<int>();
    if (n < 2) {
        return result;
    }
    std::vector<bool> input(n + 1, true);
    const int limit = (int) (std::floor(sqrt(n)) + 1);
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

    int longestCycleLength = 0;
    int longestCycleNumber = 0;

    for (int i : primeSieve(1000)) {
        if (i == 2 || i == 5) {
            continue;
        }
        int cycleLength = 1;
        int q = 10;
        while (q % i != 1) {
            ++cycleLength;
            q *= 10;
            q %= i;
        }
        if (cycleLength > longestCycleLength) {
            longestCycleLength = cycleLength;
            longestCycleNumber = i;
        }
    }

    std::cout << longestCycleNumber << std::endl;

    return 0;
}
