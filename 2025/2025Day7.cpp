#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int raysFinder(std::vector<char>& splitter, const std::vector<char>& rays){
    int splits = 0;
    int len = rays.size();
    
    for (int i = 0; i < len; i++){
        if (splitter[i] == '^' && rays[i] == '|'){
            bool alreadySplit = false;
            if (splitter[i-1] != '|' && i-1 >= 0){
                splitter[i-1] = '|';
                (!alreadySplit ? splits++ : 0);
                alreadySplit = true;
            }
            if (splitter[i+1] != '|' && i+1 < len){
                splitter[i+1] = '|';
                (!alreadySplit ? splits++ : 0);
                alreadySplit = true;
            }
        }
        else if (splitter[i] == '.' && rays[i] == '|'){
            splitter[i] = '|';
        }
    }
    return splits;
}

unsigned long long quantumCounter(const std::vector<std::vector<char>>& graph){
    std::vector<std::vector<unsigned int>> quantum;
    int len = graph.size();
    int rowSize = graph[0].size();
    
    for (int i = 0; i < len; i++){
        std::vector<unsigned int> row;
        for (int j = 0; j < rowSize; j++){
            if (i < 2){
                if (graph[i][j] == '|'){
                    row.push_back(1);
                }
                else{
                    row.push_back(0);
                }
            }
            else{
                row.push_back(0);
            }
        }
        quantum.push_back(row);
    }
    
    for (int i = 2; i < len; i++){
        for (int j = 0; j < rowSize; j++){
            if (std::ranges::find(graph[i], '^') != graph[i].end())
            {
                if (graph[i][j] == '^'){
                    quantum[i][j-1] += quantum[i-1][j];
                    quantum[i][j+1] += quantum[i-1][j];
                }
                else{
                    quantum[i][j] += quantum[i-1][j];
                }
            }
            else{
                quantum[i][j] += quantum[i-1][j];
            }
        }
    }
    
    // for (int i = 0; i < len; i++){
    //     for (int j = 0; j < rowSize; j++){
    //         std::cout << quantum[i][j] << ' ';
    //     }
    //     std::cout << "     ";
    //     for (int j = 0; j < rowSize; j++){
    //         std::cout << graph[i][j];
    //     }
    //     std::cout << '\n';
    // }
    
    unsigned long long part2res = 0;
    
    for (int i = 0; i < rowSize; i++){
        part2res += quantum[len-1][i];
    }
    
    return part2res;
}

int main()
{
    std::ifstream input("test.txt");
    std::string line;
    std::vector<std::vector<char>> graph;
    long result = 0;
    
    while(getline(input, line)){
        std::vector<char> row;
        for (char i: line){
            row.push_back(i);
        }
        graph.push_back(row);
    }

    int start = std::distance(graph[0].begin(), std::find(graph[0].begin(), graph[0].end(), 'S'));
    int len = graph.size();
    int rowSize = graph[0].size();
    
    graph[1][start] = '|';
    int totalSplits = 0;
    
    for (int i = 2; i < len; i++)
    {
        if (std::ranges::find(graph[i], '^') != graph[i].end()){
            totalSplits += raysFinder(graph[i], graph[i-1]);
        }
        else{
            for (int j = 0; j < rowSize; j++){
                if (graph[i-1][j] == '|'){
                    graph[i][j] = '|';
                }
            }
        }
    }
    
    std::cout << "Part 1: " << totalSplits << '\n';
    
    std::cout << "Part 2: " << quantumCounter(graph);
    
    return 0;
}
