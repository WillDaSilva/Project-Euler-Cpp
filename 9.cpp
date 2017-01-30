#include "toolkit.h"

int main() {

    for (int a = 1; a < 333; a++) {
        for (int b = 1; b < 500; b++) {
            if (a*a + b*b == (1000 - a - b)*(1000 - a - b)) {
                std::cout << a*b*(1000 - a - b) << std::endl;
            }
        }
    }
    return 0;
}
