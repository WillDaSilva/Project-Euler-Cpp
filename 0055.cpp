#include <iostream>
#include <algorithm>
#include "InfInt.h"

bool isPalindrome(std::string s) {
    for (int a = 0, b = s.length() - 1; a < s.length() / 2 + s.length() % 2 == 0 ? 0 : 1; ++a, --b) {
        if (s[a] != s[b]) {
            return false;
        }
    }
    return true;
}

bool isLychrel(InfInt n) {
    for (int i = 0; i < 50; ++i) {
        std::string s = n.toString();
        std::reverse(s.begin(), s.end());
        n += InfInt(s);
        if (isPalindrome(n.toString())) {
            return false;
        }
    }
    return true;
}

int main() {

    int numLychrels = 0;
    for (int i = 1; i < 10000; ++i) {
        numLychrels += isLychrel(i);
    }

    std::cout << numLychrels << std::endl;

    return 0;
}
