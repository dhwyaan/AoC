#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>

int main()
{
    std::ifstream input("input.txt");
    std::vector<std::vector<int>> grid;
    std::string line;
    std::set<std::vector<int>> visibles;
    
    while (getline(input, line)){
        std::vector<int> single;
        for (char i: line){
            single.push_back(i - '0');
        }
        grid.push_back(single);
    }
    
    const int gridL = grid.size();
    const int gridW = grid[0].size();
    
    //left right pass
    for (int i = 1; i < gridL - 1; i++){
        int left = grid[i][0];
        int right = grid[i][gridW - 1];
        for (int j = 1; j < gridW - 1; j++){
            if (left >= grid[i][j]){
                //grid[i][j] is not visible
                continue;
            }
            else {
                left = grid[i][j];
                visibles.insert({i, j});
            }
            
        }
        for (int j = gridW - 1; j > 0; j--){
            if (right >= grid[i][j]){
                //grid[i][j] is not visible
                continue;
            }
            else {
                right = grid[i][j];
                visibles.insert({i, j});
            }
            
        }
    }
    
    //top down pass
    for (int j = 1; j < gridW - 1; j++){
        int top = grid[0][j];
        int bottom = grid[gridL - 1][j];
        for (int i = 1; i < gridL - 1; i++){
            if (top >= grid[i][j]){
                //grid[i][j] is not visible
                continue;
            }
            else {
                top = grid[i][j];
                visibles.insert({i, j});
            }
            
        }
        for (int i = gridL - 1; i > 0; i--){
            if (bottom >= grid[i][j]){
                //grid[i][j] is not visible
                continue;
            }
            else {
                bottom = grid[i][j];
                visibles.insert({i, j});
            }
        }
    }
    
    std::cout << visibles.size() + 2 * (gridL + gridW) - 4 << std::endl;
    
    int scores, left, right, top, bottom = 0;
    int max_score = 0;

    for (int i = 0; i < gridL; i++) {
        for (int j = 0; j < gridW; j++) {
            int current_height = grid[i][j];
    
            int up = 0;
            for (int r = i - 1; r >= 0; r--) {
                up++;
                if (grid[r][j] >= current_height) break;
            }
            int down = 0;
            for (int r = i + 1; r < gridL; r++) {
                down++;
                if (grid[r][j] >= current_height) break;
            }
            int left = 0;
            for (int c = j - 1; c >= 0; c--) {
                left++;
                if (grid[i][c] >= current_height) break;
            }
            int right = 0;
            for (int c = j + 1; c < gridW; c++) {
                right++;
                if (grid[i][c] >= current_height) break;
            }
    
            int total_score = up * down * left * right;
            max_score = std::max(max_score, total_score);
        }
    }
    
    std::cout << max_score;
}
