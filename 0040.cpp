#include <iostream>
#include <string>
#include <cmath>

int main() {

    std::string n;
    for (int i = 0; i < 1000000; i++) {
        n.append(std::to_string(i));
    }

    int product = 1;
    for (int i = 0; i < 7; i++) {
        product *= n[std::pow(10, i)] - 48;
    }

    std::cout << product << std::endl;

    return 0;
}
