#include <iostream>
#include <cmath>
#include <algorithm>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    else if (n == 2) {
        return true;
    }
    else if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int check(std::string s) {
    int count = 0;
    for (unsigned char n = '0'; n <= '9'; ++n) {
        if (n == '0' && s[0] == '*') {
            continue;
        }
        std::string q = s;
        for (char &c : q) {
            if (c == '*') {
                c = n;
            }
        }
        count += isPrime(std::stoi(q));
    }
    return count;
}

int main() {

    int n = 1;
    while (true) {
        for (int i = 1; i < 1000; i += 2) {
            if (i % 5 == 0) {
                continue;
            }
            std::string s = std::string(n, '*') + std::to_string(i);
            std::sort(s.begin(), s.end());
            do {
                if (check(s) == 8) {
                    std::cout << s << std::endl;
                    return 0;
                }
            } while (std::next_permutation(s.begin(), s.end()));
        }
        ++n;
    }
}
