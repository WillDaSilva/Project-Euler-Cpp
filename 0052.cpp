#include <iostream>

bool isPermutation(int a, int b) {
    int c[10] = {0};
    while (a > 0) {
        ++c[a % 10];
        a /=10;
    }
    while (b > 0) {
        --c[b % 10];
        b /= 10;
    }
    bool permutation = true;
    for (int i = 0; i < 10; ++i) {
        permutation &= !c[i];
    }
    return permutation;
}

int main() {

    int n = 1;
    while (true) {
        int i;
        for (i = 2; i <= 6; ++i) {
            if (!isPermutation(n, i * n)) {
                break;
            }
        }
        if (i == 7) {
            break;
        }
        ++n;
    }

    std::cout << n << std::endl;

    return 0;
}
