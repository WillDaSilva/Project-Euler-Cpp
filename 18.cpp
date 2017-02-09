#include "toolkit.h"

int main() {

    std::ifstream input("18.txt");
    std::vector<std::vector<int>> triangle;

    for (std::string line; std::getline(input, line);) {
        std::vector<int> values;
        std::string buffer;
        std::stringstream ss(line);
        while (ss >> buffer) {
            values.push_back(atoi(buffer.c_str()));
        }
        triangle.push_back(values);
    }

    for (int y = triangle.size() - 1; y >= 0; y--) {
        for (int x = 0; x < triangle[y].size() - 1; x++) {
            triangle[y-1][x] += triangle[y][x] < triangle[y][x + 1] ? triangle[y][x + 1] : triangle[y][x];
        }
    }

    std::cout << triangle[0][0] << std::endl;

    return 0;
}
