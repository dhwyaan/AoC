#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::ifstream input("input.txt");
    std::vector<std::string> boardState;
    std::string oneLine;
    
    //get input (initial board state)
    while (getline(input, oneLine)){
        boardState.push_back(oneLine);
    }
    input.close();
    int lines = boardState.size();
    std::vector<std::stack<char>> stacks;
    
    std::map<int, int> indices;
    int counter = 0;
    
    //creates a vector of stacks and saves the indices where the relevant data is.
    //Map indices(counter: i) is where the ith column is located, counter is the column.
    for (int i = 0; i < boardState[lines - 1].length(); i++){
        char j = boardState[lines-1][i];
        if (j >= 48 && j <= 57){
            std::stack<char> myStack;
            stacks.push_back(myStack); //stacks is a vector numbered from 0 to 8
            indices[counter] = i;  //indices keys are numbered from 0 to 8
            counter++;
        }
    }
    
    //pushes the relevant colums into stacks
    //First for loop reads data from the bottom up and saves it as a string to oneLine
    //Second for loop reads the line 
    for (int i = lines - 2; i >= 0 ; i--){
        oneLine = boardState[i];
        for (int j = 0; j < oneLine.size(); j++){
            if (oneLine[indices[j]] >= 'A' && oneLine[indices[j]] <= 'Z'){
                stacks[j].push(oneLine[indices[j]]);
            }
        }
    }
    
    // check if the input is being read correctly
    // for (int i = 0; i < counter; i++){
    //     std::stack j = stacks[i];
    //     while (!j.empty()){
    //         std::cout << j.top();
    //         j.pop();
    //     }
    //     std::cout << std::endl;
    // }
    
    std::ifstream instructions("instructions.txt");
    std::string dummy1, dummy2, dummy3;
    int quantity, source, destination;
    char moved;

    while (instructions >> dummy1 >> quantity >> dummy2 >> source >> dummy3 >> destination){
        for (int i = 0; i < quantity; i++){
            if (!stacks[source - 1].empty()){
                moved = stacks[source - 1].top();
                stacks[source - 1].pop();
                stacks[destination - 1].push(moved);
            }
        }
    }

    /*    SOLUTION FOR PART 2, UNCOMMENT THIS AND COMMENT THE ABOVE BLOCK TO USE
        while (instructions >> dummy1 >> quantity >> dummy2 >> source >> dummy3 >> destination){
        std::stack<char> temp;
        for (int i = 0; i < quantity; i++){
            if (!stacks[source - 1].empty()){
                moved = stacks[source - 1].top();
                stacks[source - 1].pop();
                temp.push(moved);
            }
        }
        for (int i = 0; i < quantity; i++){
            while (!temp.empty()){
                stacks[destination - 1].push(temp.top());
                temp.pop();
            }
        }
    }
    */
    
    for (int i = 0; i < stacks.size(); i++){
        std::stack j = stacks[i];
        if (!j.empty()){
            std::cout << j.top();
        }
    }
}
