#include <iostream>

int main() {

    int sum = 1;
    int previous = 1;

    for (int i = 1; i < 1001/2 + 1; i++) {
        for (int j = 0; j < 4; j++) {
            previous += 2*i;
            sum += previous;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
