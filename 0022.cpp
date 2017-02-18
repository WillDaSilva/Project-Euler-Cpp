#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

unsigned long int nameValue(const std::string &s) {
    unsigned long int value = 0;
    for (char c : s) {
        if (c != '\"') {
            value += c - 64;
        }
    }
    return value;
}

int main() {

    std::ifstream input("22.txt");
    std::vector<std::string> names;
    std::string namesString;
    getline(input, namesString);
    input.close();

    names = split(namesString, ',');
    std::sort(names.begin(), names.end());

    unsigned long long int sum = 0;
    for (int i = 0; i < names.size(); i++) {
        sum += nameValue(names[i]) * (i + 1);
    }

    std::cout << sum << std::endl;

    return 0;
}
