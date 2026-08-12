#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

int toggler(const std::vector<std::vector<int>>& switches, std::map<std::vector<bool>, int>& noOfPresses, std::vector<bool>& currentState, const std::vector<bool>& goal, int pressed) {
    if (currentState == goal) {
        return pressed;
    }
    int min_toggles = 1e9;

    for (const std::vector<int>& i : switches) {
        std::vector<bool> backup = currentState;
        for (int j : i) {
            currentState[j] = !currentState[j];
        }
        if (noOfPresses.contains(currentState) && noOfPresses[currentState] <= pressed + 1) {
            currentState = backup;
            continue;
        }
        else {
            noOfPresses[currentState] = pressed + 1;
        }
        int result = toggler(switches, noOfPresses, currentState, goal, pressed + 1);
        
        if (result != 0) {
            min_toggles = std::min(min_toggles, result);
        }
        currentState = backup;
    }
    return (min_toggles == 1e9) ? 0 : min_toggles;
}


int main()
{
	std::ifstream input("input.txt");
	std::string line;
	int result = 0;

	while (std::getline(input, line)) {
		std::vector<bool> goal = {};
		size_t opening = line.find('[');
		size_t closing = line.find(']');
		for (size_t i = opening; i < closing; i++) {
			if (line[i] == '.') {
				goal.push_back(false);
			}
			else if (line[i] == '#') {
				goal.push_back(true);
			}
		}

		std::vector<std::vector<int>> switches;

		while (line.find('(') != std::string::npos) {
			opening = line.find('(');
			closing = line.find(')');
			line[opening] = ' ';
			line[closing] = ' ';
			std::string num;
			std::stringstream ss(line.substr(opening, closing - opening));
			std::vector<int> currentSwitch;
			while (std::getline(ss, num, ',')) {
				currentSwitch.push_back(std::stoi(num));
			}
			switches.push_back(currentSwitch);
		}

		//the keys are the switches that are on, the values are the number of presses required
		std::map<std::vector<bool>, int> noOfPresses;

		//since all switches start at off position
		std::vector<bool> currentState(goal.size(), false);

		result += toggler(switches, noOfPresses, currentState, goal, 0);

		// for (bool i: goal){
		//     std::cout << (i ? 1 : 0);
		// }
		// std::cout << "   ";
		// for (std::vector<int> i: switches){
		//     for (int j: i){
		//         std::cout << j;
		//         std::cout << ",";
		//     }
		//     std::cout << "    ";
		// }
		// std::cout << '\n';
	}

	std::cout << result;
}
