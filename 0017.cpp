#include <iostream>
#include <unordered_map>

typedef std::unordered_map<int, int> map;

int wordValue(int n) {

    static map d1 = {{1,3},{2,3},{3,5},{4,4},{5,4},{6,3},{7,5},{8,5},{9,4},{10,3},{11,6},{12,6},{13,8},{14,8},{15,7},{16,7},{17,9},{18,8},{19,8}};
    static map d2 = {{2,6},{3,6},{4,5},{5,5},{6,5},{7,7},{8,6},{9,6}};

    if (n == 1000) return 11;
    int value = 0;
    if (n > 99) value += d1[(n - (n % 100)) / 100] + 7;
    if (n > 100 && n % 100 != 0) value += 3;
    if (n % 100 < 20) value += d1[n % 100];
    else value += d2[((n % 100) - (n % 10)) / 10] + d1[n % 10];
    return value;
}

int main() {

    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        sum += wordValue(i);
    }

    std::cout << sum << std::endl;

    return 0;
}
