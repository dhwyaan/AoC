#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
#include <sstream>

int main()
{
	std::ifstream input("input.txt");
	std::string line;
	std::array<int, 3> triangle;
	int counter = 0;

	while (getline(input, line)) {
		std::stringstream sides(line);
		sides >> triangle[0] >> triangle[1] >> triangle[2];
		std::sort(triangle.begin(), triangle.end());
		if (triangle[0] + triangle[1] > triangle[2]) {
			counter++;
		}
	}

	std::cout << "Part 1: "<< counter;

	input.clear();
	input.seekg(0, std::ios::beg);

	counter = 0;
	int lineNo = 0;
	std::array<std::array<int, 3>, 3> verticalTriangle;

	while (getline(input, line)) {
		std::stringstream sides(line);
		sides >> verticalTriangle[lineNo%3][0] >> verticalTriangle[lineNo%3][1] >> verticalTriangle[lineNo%3][2];
		if ((lineNo+1)%3 == 0) {
			for (int col = 0; col < 3; col++) {
				for (int row = 0; row < 3; row++) {
					triangle[row] = verticalTriangle[row][col];
				}
				std::sort(triangle.begin(), triangle.end());
				if (triangle[0] + triangle[1] > triangle[2]) {
					counter++;
				}
			}
		}
		lineNo++;
	}

	std::cout << "\nPart 2: "<< counter;
}
