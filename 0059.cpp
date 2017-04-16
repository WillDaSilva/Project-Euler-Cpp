#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<char> split(const std::string &s, char delim) {
    std::vector<char> elems;
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::stoi(item));
    }
    return elems;
}

int main() {

    std::ifstream input("0059.txt");
    std::string inputString;
    std::getline(input, inputString);
    input.close();

    std::vector<char> encryptedVector = split(inputString, ',');
    std::string encryptedString;
    for (std::vector<char>::iterator it = encryptedVector.begin(); it != encryptedVector.end(); ++it) {
        encryptedString += *it;
    }

    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            for (char c = 'a'; c <= 'z'; ++c) {
                std::string encrypted = encryptedString;
                int i = 0;
                std::string key = std::string(1, a) + std::string(1, b) + std::string(1, c);
                std::for_each(encrypted.begin(), encrypted.end(), [&i, &key, &a, &b, &c](char& z){
                    ++i;
                    i %= 3;
                    z ^= key[i];
                });
                bool found = true;
                for (std::string::iterator it = encrypted.begin(); it != encrypted.end(); ++it) {
                    if (!((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z') || (*it >= '0' &&  *it <= '9')
                        || *it <= ' ' || *it == ',' || *it == '.' || *it == '\'' || *it == '(' || *it == ')' || *it == '!' || *it == '?' || *it == ';' || *it == ':')) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    int sum = 0;
                    for (std::string::iterator it = encrypted.begin(); it != encrypted.end(); ++it) {
                        sum += *it;
                    }
                    std::cout << sum << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
