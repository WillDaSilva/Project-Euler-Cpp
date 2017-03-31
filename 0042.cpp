#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

int getWordValue(std::string word) {
    int wordValue = 0;
    for (char c : word) {
        wordValue += c - 64;
    }
    return wordValue;
}

bool isTriangleWord(std::string word) {
    int n = getWordValue(word);
    int x = std::sqrt(2 * n);
    return x * (x + 1) / 2 == n;
}

int main() {

    std::string words;
    std::ifstream input("0042.txt");
    std::getline(input, words);
    input.close();
    std::stringstream ss;
    ss.str(words);
    std::string word;
    int numTriangleWords = 0;
    while (std::getline(ss, word, ',')) {
        numTriangleWords += isTriangleWord(std::string(word, 1, word.length() - 2));
    }

    std::cout << numTriangleWords << std::endl;

    return 0;
}
