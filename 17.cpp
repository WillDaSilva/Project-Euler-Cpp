#include "toolkit.h"

typedef std::unordered_map<int, int> map;

int wordValue(int n, map & d1, map & d2) {

    if (n == 1000) return 11;
    int value = 0;
    if (n > 99) value += d1[(n - (n % 100)) / 100] + 7;
    if (n > 100 && n % 100 != 0) value += 3;
    if (n % 100 < 20) value += d1[n % 100];
    else value += d2[((n % 100) - (n % 10)) / 10] + d1[n % 10];
    return value;
}

int main() {

    map d1;
    d1[0] = 0;  d1[1] = 3;  d1[2] = 3;  d1[3] = 5;  d1[4] = 4;  d1[5] = 4;  d1[6] = 3;  d1[7] = 5;  d1[8] = 5;  d1[9] = 4;
    d1[10] = 3; d1[11] = 6; d1[12] = 6; d1[13] = 8; d1[14] = 8; d1[15] = 7; d1[16] = 7; d1[17] = 9; d1[18] = 8; d1[19] = 8;
    map d2;
    d2[0] = 0; d2[2] = 6; d2[3] = 6; d2[4] = 5; d2[5] = 5; d2[6] = 5; d2[7] = 7; d2[8] = 6; d2[9] = 6;

    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += wordValue(i, d1, d2);
    }

    std::cout << sum << std::endl;

    return 0;
}
