#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

bool colorChecker(std::string& colorname, int color){
    std::unordered_map<std::string, int> maxCubes = {{"blue", 14}, {"red", 12}, {"green", 13}};
    return maxCubes[colorname] >= color;
    //return color <= maxCubes[colorname]; this is the same thing as above
}

int main(){
    std::ifstream input("input.txt");
    std::string line;
    int total = 0;
    long power = 0;
    
    while (getline(input, line)){
        int colonPos = line.find(':');
        int gameNo = 0;
        std::string game;
        std::stringstream(line.substr(0, colonPos)) >> game >> gameNo;
        bool validity = true;
        
        int color;
        std::string colorname;
        game = line.substr(colonPos+1);
        std::replace(game.begin(), game.end(), ',', ' ');
        std::replace(game.begin(), game.end(), ';', ' ');
        std::stringstream ss = std::stringstream(game);
        std::unordered_map<std::string, int> maxValues = {{"blue", 0}, {"red", 0}, {"green", 0}};
        
        while (ss >> color >> colorname){
            validity = validity && colorChecker(colorname, color);
            if (maxValues[colorname] < color){
                maxValues[colorname] = color;
            }
        }
        
        if (validity){
            total += gameNo;
        }
        
        int temp = 1;
        for (auto it = maxValues.begin(); it != maxValues.end(); it++){
            temp *= it->second;
        }
        
        power += temp;
    }
    
    std::cout << "Answer Part 1: "<< total << std::endl;
    std::cout << "Answer Part 2: "<< power;
}
