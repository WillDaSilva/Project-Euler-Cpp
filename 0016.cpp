#include <iostream>
#include <vector>

std::vector<int> largePowerOfTwo(int n) {
    std::vector<int> r;
    r.push_back(1);
    for (int i = 0; i < n; ++i) {
        for (auto &e : r) {
            e *= 2;
        }
        for (int j = 0; j < r.size(); ++j) {
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
    std::vector<int> t = largePowerOfTwo(1000);

    for (auto &e : t) {
        sum += e;
    }

	std::cout << sum << std::endl;
}
