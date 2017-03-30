#include <iostream>
#include <string>
#include <bitset>

bool isPalindrome(std::string s) {
    for (int a = 0, b = s.length() - 1; a < s.length() / 2 + s.length() % 2 == 0 ? 0 : 1; a++, b--) {
        if (s[a] != s[b]) {
            return false;
        }
    }
    return true;
}

int main() {

    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        std::string binaryNum = std::bitset<20>(i).to_string();
        if (isPalindrome(std::to_string(i)) && isPalindrome(std::string(binaryNum, binaryNum.find_first_not_of('0')))) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
