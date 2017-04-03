#include <iostream>

double choose(double n, double k) {
	double p = 1;
	for (int i = 1; i <= k; ++i) {
        p *= (n + 1 - i) / i;
    }
	return p;
}

int main() {

    std::cout.precision(16);
    std::cout  << choose(40,20) << std::endl;

    return 0;
}
