#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

std::string trim(const std::string& str) {
    const std::string whitespace = " \t\n\r\f\v";
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        return "";
    }
    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}

bool isInteger(const std::string& str) {
    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

int main(){
     std::ifstream input("input.txt");
     std::string line;
     std::unordered_map<std::string, std::string> undetermined;
     std::unordered_map<std::string, long long> determined;
     
     while(getline(input, line)){
         int pos = line.find(':');
         std::string name = trim(line.substr(0, pos));
         std::string value = trim(line.substr(pos+1));

         if (isInteger(value)){
             determined[name] = std::stoll(value);
         }
         else{
             undetermined[name] = value;
         }
    }
    
    //Check if input is being read correctly
    
    // for(auto it = determined.begin(); it != determined.end(); it++){
    //     std::cout << it->first << "..." << it->second<< std::endl;
    // }
        
    // for(auto it = undetermined.begin(); it != undetermined.end(); it++){
    //     std::cout << it->first << "..." << it->second << std::endl;
    // }
    
    while (!determined.contains("root")){
        std::string name;
        std::string equation;
        std::string first, second;
        char oper;
        for (auto it = undetermined.begin(); it != undetermined.end(); ){
            name = it->first;
            equation = it->second;
            if (std::stringstream(equation) >> first >> oper >> second) {
                if (determined.contains(trim(first)) && determined.contains(trim(second))){
                    switch (oper){
                        case '+':
                        determined[trim(name)] = determined[trim(first)] + determined[trim(second)];
                        it = undetermined.erase(it); 
                        break;
                        
                        case '-':
                        determined[trim(name)] = determined[trim(first)] - determined[trim(second)];
                        it = undetermined.erase(it); 
                        break;
                        
                        case '*':
                        determined[trim(name)] = determined[trim(first)] * determined[trim(second)];
                        it = undetermined.erase(it); 
                        break;
                        
                        case '/':
                        determined[trim(name)] = determined[trim(first)] / determined[trim(second)];
                        it = undetermined.erase(it); 
                        break;
                    }
                }
                else{
                    it++;
                }
            }
        }
    }
    std::cout << determined["root"];
}
