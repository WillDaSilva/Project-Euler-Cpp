#include <iostream>
#include <vector>

std::vector<int> largeFactorial(int n) {
    std::vector<int> r;
    r.push_back(1);
    for (int i = 2; i <= n; i++) {
        for (auto &e : r) {
            e *= i;
        }
        for (int j = 0; j < r.size(); j++) {
            if (r[j] >= 10) {
                if (j+1 != r.size()) {
                    r[j+1] += (r[j] - (r[j] % 10)) / 10;
                }
                else {
                    r.push_back((r[j] - (r[j] % 10)) / 10);
                }
                r[j] = r[j] % 10;
            }
        }
    }
    return r;
}

int main() {

    int sum = 0;
    std::vector<int> f = largeFactorial(100);

    for (auto &e : f) {
        sum += e;
    }

    std::cout << sum << std::endl;

    return 0;
}
