#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int position = 50;
    int counter = 0;
    
    while (getline(input, line)){
        int change = std::stoi(line.substr(1));
        change %= 100;
        if (line[0] == 'R'){
            position += change;
            while (position >= 100){
                position %= 100;
            }
        }
        else if (line[0] == 'L'){
            position -= change;
            while (position < 0){
                position += 100;
            }
        }
        
        if (position == 0){
            counter++;
        }
    }
    std::cout << counter;
}


/* PART 2
    #include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int position = 50;
    int counter = 0;
    
    while (getline(input, line)){
        int change = std::stoi(line.substr(1));
        char direction = line[0];
        for (int i = 0; i < change; i++){
            switch (direction){
                case 'L':
                position--;
                break;
                
                case 'R':
                position++;
                break;
            }
            if (position<0){
                position += 100;
            }
            else if (position>=100){
                position -= 100;
            }
            if (position == 0){
                counter++;
            }
        }
    }
    std::cout << counter;
}

*/
