#include <iostream>

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

int numCombinations(int sum, int largestCoin) {
    if (sum < 0) {
        return 0;
    }
    if (sum == 0 || largestCoin == 1) {
        return 1;
    }
    else {
        return numCombinations(sum, largestCoin - 1) + numCombinations(sum - coins[largestCoin - 1], largestCoin);
    }
}

int main() {

    std::cout << numCombinations(200, 8) << std::endl;

    return 0;
}
