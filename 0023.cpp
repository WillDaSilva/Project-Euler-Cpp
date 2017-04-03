#include <iostream>
#include <vector>

int sumProperDivisors(int n) {
    int sum = 1;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i*i != n) {
                sum += n/i;
            }
        }
    }
    return sum;
}

int main() {

    int limit = 28123;
    std::vector<int> abundants;
    for (int i = 1; i < limit; ++i) {
        if (sumProperDivisors(i) > i) {
            abundants.push_back(i);
        }
    }

    bool isSumOfAbundants[limit];
    for(int a = 0; a < abundants.size(); ++a) {
        for (int b = a; b < abundants.size(); ++b) {
            if (abundants[a] + abundants[b] < limit) {
                isSumOfAbundants[abundants[a] + abundants[b]] = true;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < limit; ++i) {
        if (!isSumOfAbundants[i]) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
