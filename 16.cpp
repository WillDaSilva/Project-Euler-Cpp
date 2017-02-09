#include "toolkit.h"

int main() {

    int exponent = 1000;
	int digits[320] = {2};

	int size = 1;
    int sum = 2;

	for (int i=1; i < exponent; i++) {

        sum *= 2;
		for (int n = 0; n < size; n++) {
			if (digits[n] >= 5)
				sum -= 9;
			digits[n] *= 2;
		}

        for (int n = 0; n < size; n++) {
			if (digits[n] > 9) {
				digits[n] -= 10;
				digits[n + 1] += 1;
				if (n + 1 == size) {
                    ++size;
                }
			}
		}
	}
	std::cout << sum << std::endl;
}
