#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <set>

int removableCounter (std::vector<std::vector<char>>& rolls)
{
    const std::set<std::array<int, 2>> neighbors
    {{-1, -1}, {-1, 0}, {-1, 1},
      {0, -1},           {0, 1},
      {1, -1},  {1, 0},  {1, 1}};
     
    int counter = 0;
    const int numRows = rolls.size();
    const int numCols = rolls[0].size();
    
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            int num = 0;
            
            if (rolls[i][j] == '@')
            {
                for (std::array<int, 2> elem: neighbors)
                {
                    if (i + elem.at(0) >= 0 && i + elem.at(0) < numRows &&
                        j + elem.at(1) >= 0 && j + elem.at(1) < numCols)
                        {
                            if (rolls.at(i+elem[0]).at(j+elem[1]) == '@' || rolls.at(i+elem[0]).at(j+elem[1]) == 'x'){
                                num++;
                            }
                        }
                }
                if (num < 4){
                    counter++;
                    rolls[i][j] = 'x';
                }
            }
            
            else{
                continue;
            }
        }
    }
    return counter;
}

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    std::vector<std::vector<char>> rolls;
    
    while (getline(input, line)){
        std::vector<char> row;
        for (char i: line){
            row.push_back(i);
        }
        rolls.push_back(row);
    }
    
    int counter = removableCounter(rolls);
    
    std::cout << "Part 1: " << counter;
    int prevCounter = 0;
    
    while (prevCounter != counter){
        prevCounter = counter;
        int numRows = rolls.size();
        int numCols = rolls[0].size();
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                if (rolls[i][j] == 'x'){
                    rolls[i][j] = '.';
                }
            }
        }
        counter += removableCounter(rolls);
    }
    
    std::cout << "\nPart 2: " << counter;
}
