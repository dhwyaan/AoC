#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{
	std::ifstream ranges("ranges.txt");
	std::string line;
	std::vector<std::array<long, 2>> range;

	while (getline(ranges, line))
	{
		std::string num1, num2;
		std::stringstream edited(line);
		std::getline(edited, num1, '-');
		std::getline(edited, num2);
		std::array<long, 2> pair = {std::stol(num1), std::stol(num2)};
		range.push_back(pair);
	}

	int counter = 0;
	std::ifstream data("data.txt");
	std::sort(range.begin(), range.end());
	
	std::vector<std::array<long, 2>> merged;
    merged.push_back(range[0]);
    
    for (int i = 1; i < range.size(); i++) {
        std::array<long, 2> last = merged.back();
        if (range[i][0] <= last[1]) {
            last[1] = std::max(last[1], range[i][1]);
        } else {
            merged.push_back(range[i]);
        }
    }
    
    range = merged;
    long valid = 0;
    
    for (std::array<long, 2> i: range) {
	    valid += i[1] - i[0] + 1;
    }
	
	while (getline(data, line)) {
		long thisnum = std::stol(line);
		for (std::array<long, 2> i: range) {
		    if (thisnum >= i.at(0) && thisnum <= i.at(1)) {
				counter++;
				break;
			}
		}
	}
	std::cout << "Part 1: "<< counter;
	std::cout << "\nPart 2: "<< valid;
}
