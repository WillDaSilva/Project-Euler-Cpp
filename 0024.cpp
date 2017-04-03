#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 1000000; ++i) {
        if (i == 999999) {
            for (std::vector<int>::const_iterator iter = digits.begin(); iter != digits.end(); ++iter) {
                std::cout << *iter;
            }
        }
        std::next_permutation(digits.begin(), digits.end());
    }

    return 0;
}
