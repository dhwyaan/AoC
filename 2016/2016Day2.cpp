#include <iostream>
#include <fstream>
#include <array>
#include <string>

std::string part1(std::ifstream& input){
    std::array<std::array<char, 3>, 3> keypad = {{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}};
    std::string line;
    std::string num = "";
    std::array<int, 2> pos = {1, 1};
    
    while (getline(input, line)){
        for (char i: line){
            switch (i){
                case 'R':
                (pos[1] <= 1 ? pos[1] += 1 : pos [1]);
                break;
                
                case 'L':
                (pos[1] >= 1 ? pos[1] -= 1 : pos [1]);
                break;
                
                case 'U':
                (pos[0] >= 1 ? pos[0] -= 1 : pos [0]);
                break;
                
                case 'D':
                (pos[0] <= 1 ? pos[0] += 1 : pos [0]);
                break;
            }
        }
        num += keypad[pos[0]][pos[1]];
    }
    input.seekg(0, std::ios::beg);
    return num;
}

std::string part2(std::ifstream& input){
    std::array<std::array<char, 5>, 5> keypad = {{{'-', '-', '1', '-', '-'}, {'-', '2', '3', '4', '-'}, {'5', '6', '7', '8', '9'}, {'-', 'A', 'B', 'C', '-'}, {'-', '-', 'D', '-', '-'}}};
    std::string line;
    std::string num = "";
    std::array<int, 2> pos = {2, 0};
    
    while (getline(input, line)){
        for (char i: line){
            switch (i){
                case 'R':
                (keypad[pos[0]][pos[1] + 1] != '-' && pos[1] <= 3 ? pos[1] += 1 : pos [1]);
                break;
                
                case 'L':
                (keypad[pos[0]][pos[1] - 1] != '-' && pos[1] >= 1 ? pos[1] -= 1 : pos [1]);
                break;
                
                case 'U':
                (keypad[pos[0] - 1][pos[1]] != '-' && pos[0] >= 1 ? pos[0] -= 1 : pos [0]);
                break;
                
                case 'D':
                (keypad[pos[0] + 1][pos[1]] != '-' && pos[0] <= 3 ? pos[0] += 1 : pos [0]);
                break;
            }
        }
        num += keypad[pos[0]][pos[1]];
    }
    input.seekg(0, std::ios::beg);
    return num;
}

int main()
{
    std::ifstream input("input.txt");
    
    //std::cout << part1(input) << '\n';
    
    std::cout << part2(input);
    
    
}
