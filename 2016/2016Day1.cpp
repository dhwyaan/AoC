#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

char newDirection(char currFacing, bool directionR){
    std::string directions= "WNES";
    int index = directions.find(currFacing) + (directionR ? +1 : -1);
    index = (index < 0 ? index+4 : index);
    index = (index > 3 ? index%4 : index);
    return directions[index];
}

int main()
{
    std::ifstream input("test.txt");
    std::string line;
    char currFacing = 'N';
    int NorthSouth = 0;
    int WestEast = 0;
    std::vector<std::array<int, 2>> visited;
    
    while (getline(input, line, ',')){
        int i = 0;
        bool directionR;
        for (i = 0; i < line.length(); i++)
        {
            if (line[i] == 'L'){
                directionR = false;
                break;
            }
            else if (line[i] == 'R'){
                directionR = true;
                break;
            }
        }
        int distance = stoi(line.substr(i+1));
        currFacing = newDirection(currFacing, directionR);
        
        for (int step = 0; step < distance; ++step) {
            switch (currFacing) {
                case 'N': ++NorthSouth; break;
                case 'S': --NorthSouth; break;
                case 'E': ++WestEast;   break;
                case 'W': --WestEast;   break;
            }
        
            std::array<int, 2> currentlyHere{NorthSouth, WestEast};
        
            if (std::find(visited.begin(), visited.end(), currentlyHere) != visited.end()) {
                std::cout << "Part 2 Solution: " << std::to_string(NorthSouth) << " " << std::to_string(WestEast) << '\n';
            }
        
            visited.push_back(currentlyHere);
        }
    }
    
    std::cout << "Part 1 Solution: " << std::to_string(NorthSouth) << " " << std::to_string(WestEast);
}
