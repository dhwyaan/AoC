#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int result = 0;
    
    while(getline(input, line)){
        int len = line.size();
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
    }
    std::cout << result;
}
