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
    
    // for (std::vector<char> line: graph){
    //     for (char i: line){
    //         std::cout << i;
    //     }
    //     std::cout << '\n';
    // }
    
}
