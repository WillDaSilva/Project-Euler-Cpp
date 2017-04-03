#include <iostream>

double choose(double n, double r) {
	double p = 1;
	for (int i = 1; i <= r; ++i) {
        p *= (n + 1 - i) / i;
    }
	return p;
}

int main() {

    int n = 0;
    for (int a = 1; a <= 100; ++a) {
        for (int b = 0; b <= a; ++b) {
            if (choose(a, b) > 1000000) {
                ++n;
            }
        }
    }

    std::cout << n << std::endl;

    return 0;
}
