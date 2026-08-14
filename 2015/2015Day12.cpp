#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int linesum (std::string line){
    int len = line.size();
    int result = 0;
    for (int i = 0; i < len; i++){
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'){
            continue;
        }
        else{
            line[i] = ' ';
        }
    }
    std::stringstream ss(line);
    std::string num;
    while(ss >> num){
        result += std::stoi(num);
    }
    return result;
}

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int result = 0;
    
    while(getline(input, line)){
        result += linesum(line);
    }
    std::cout << result;
}
