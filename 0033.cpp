#include <iostream>

int gcd(int a, int b) {
    if (a < b) {
        int c = a;
        a = b;
        b = c;
    }
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    int n = 1;
    int d = 1;

    // All of the fractions we are looking for have this form:
    // 10c + a   c
    // ------- = -
    // 10a + b   b

    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < a; b++) {
            for (int c = 1; c < b; c++) {
                if ((c * 10 + a) * b == c * (a * 10 + b)) {
                    n *= (c * 10 + a);
                    d *= (a * 10 + b);
                }
            }
        }
    }

    std::cout << d / gcd(n, d) << std::endl;

    return 0;
}
