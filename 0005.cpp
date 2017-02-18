#include <iostream>

int main() {

    int n = 0;
    bool found;
    while (true) {
        n++;
        found = true;
        for (int i = 1; i < 21; i++) {
            if (n % i != 0) {
                found = false;
            }
        }
        if (found) {
            std::cout << n << std::endl;
            break;
        }
    }

    return 0;
}
