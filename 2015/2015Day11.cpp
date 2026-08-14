#include <iostream>
#include <string>

bool first(const std::string& password){
    int len = password.size();
    for (int i = 0; i < len - 2; i++){
        if (password[i + 1] == password[i] + 1  && password[i + 2] == password[i] + 2){
            return true;
        }
    }
    return false;
}

bool second(const std::string& password){
    if (password.find('i') != std::string::npos || password.find('o') != std::string::npos || password.find('l') != std::string::npos){
        return false;
    }
    return true;
}

bool third(const std::string& password){
    int count = 0;
    int len = password.size();
    for (int i = 0; i < len - 1; i++){
        if (password[i] == password[i+1]){
            count++;
            i++;
        }
    }
    return count >= 2;
}

void increment(std::string& password){
    int len = password.size() - 1;
    if (password[len] != 'z'){
        password[len] += 1;
    }
    else{
        while (password[len] == 'z'){
            password[len] = 'a';
            len--;
            if (len == -1){
                break;
            }
        }
        password[len]++;
    }
}

int main(){
    std::string password = "cqjxjnds";
    
    while (!first(password) || !second(password) || !third(password)){
        increment(password);
    }
    
    std::cout << "Part 1: "<<  password;
    
    increment(password);
    
    while (!first(password) || !second(password) || !third(password)){
        increment(password);
    }
    
    std::cout << "\nPart 2: "<<  password;
    
    return 0;
}
