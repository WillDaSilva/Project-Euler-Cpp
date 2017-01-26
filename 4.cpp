#include "toolkit.h"

int main () {

    int largest = 0;
    int q;
    for (int i = 100; i < 999; i++) {
        for (int j = 100; j < 999; j++) {
            q = (i*j);
            int n = 0;                                      // length of q
            while (q != (q % (int)(std::pow(10,++n)))){}    // calculate n
            bool palindrome = true;
            for (int k = 0; k < n; k++) {
                if (std::floor(((q % (int)std::floor(std::pow(10,n-k))) / std::floor(std::pow(10,n-k-1)))) != std::floor(((q % (int)std::floor(std::pow(10,k+1))) / std::floor(std::pow(10,k))))) {
                    palindrome = false;
                }
            }
            if (palindrome && q > largest) {
                largest = q;
            }
        }
    }

    std::cout << largest << std::endl;

    return 0;

}
