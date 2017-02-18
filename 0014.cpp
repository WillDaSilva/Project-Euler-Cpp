#include <iostream>
#include <unordered_map>

int main() {

    std::unordered_map<int, int> table;

    int longestChain = 0;
    int longestChainStartingNum = 0;
    for (int i = 999999; i > 1; i--) {
        long long n = i;
        int chain = 0;
        while (true) {
            if (n == 1) {
                if (table.count(i) == 0) {
                    table[i] = chain;
                }
                if (chain > longestChain) {
                    longestChain = chain;
                    longestChainStartingNum = i;
                }
                break;
            }
            else if (table.count(n) == 1) {
                chain += table[n];
                if (chain > longestChain) {
                    longestChain = chain;
                    longestChainStartingNum = i;
                }
                break;
            }
            else if (n % 2 == 0) {
                n = (n/2);
                chain++;
            }
            else {
                n = ((n * 3) + 1);
                chain++;
            }
        }
    }

    std::cout << longestChainStartingNum << std::endl;

    return 0;
}
