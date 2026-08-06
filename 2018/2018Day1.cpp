#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main() {
    std::ifstream input("input.txt");

    std::vector<int> changes;
    std::string line;

    while (std::getline(input, line)) {
        changes.push_back(std::stoi(line));
    }

    int part1 = 0;
    for (int change : changes) {
        part1 += change;
    }

    std::unordered_set<int> seen{0};
    int frequency = 0;

    while (true) {
        for (int change : changes) {
            frequency += change;
            if (!seen.insert(frequency).second) {
                std::cout << "Part 1: " << part1 << '\n';
                std::cout << "Part 2: " << frequency << '\n';
                return 0;
            }
        }
    }
}
