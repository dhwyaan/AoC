#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <chrono>

int main()
{
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Could not open input.txt\n";
        return 1;
    }

    const int rows = 100;
    const int cols = 100;
    std::array<std::array<bool, cols>, rows> boardState = {};
    std::array<std::array<bool, cols>, rows> tempState = {};
    std::string Line;
    
    for (int i = 0; i < rows; i++){
        getline(input, Line);
        for (int j = 0; j < cols; j++){
            boardState[i][j] = (Line[j] == '#');
        }
    }
    input.close();

    std::array<std::array<int, 2>, 8> deltas = {{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

    // --- START TIMING ---
    auto start = std::chrono::high_resolution_clock::now();

    for (int gen = 0; gen < 100; gen++){
        boardState.at(0).at(0) = true;
        boardState.at(rows-1).at(0) = true;
        boardState.at(rows-1).at(cols-1) = true;
        boardState.at(0).at(cols-1) = true;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                int count = 0;
                for (auto d: deltas){
                    try { 
                        count += (boardState.at(i + d[0]).at(j + d[1]) ? 1 : 0); 
                    }
                    catch (std::out_of_range const& error){ ; }
                }
                if (boardState.at(i).at(j) == true){
                    if (count == 2 || count == 3){tempState.at(i).at(j) = true;}
                    else {tempState.at(i).at(j) = false;}
                }
                else {
                    if (count == 3){ tempState.at(i).at(j) = true;}
                    else {tempState.at(i).at(j) = false;}
                }
            }
        }
        boardState = tempState;
    }
    boardState.at(0).at(0) = true;
    boardState.at(rows-1).at(0) = true;
    boardState.at(rows-1).at(cols-1) = true;
    boardState.at(0).at(cols-1) = true;

    auto end = std::chrono::high_resolution_clock::now();
    // --- END TIMING ---

    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            count += (boardState.at(i).at(j) ? 1 : 0);
        }
    }

    std::cout << "Result: " << count << "\n";
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken (Try-Catch): " << duration.count() << " ms\n";
}




____________________________________________________________________________________




#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <chrono>

int main()
{
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Could not open input.txt\n";
        return 1;
    }

    const int rows = 100;
    const int cols = 100;
    std::array<std::array<bool, cols>, rows> boardState = {};
    std::array<std::array<bool, cols>, rows> tempState = {};
    std::string Line;
    
    for (int i = 0; i < rows; i++){
        getline(input, Line);
        for (int j = 0; j < cols; j++){
            boardState[i][j] = (Line[j] == '#');
        }
    }
    input.close();

    std::array<std::array<int, 2>, 8> deltas = {{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

    // --- START TIMING ---
    auto start = std::chrono::high_resolution_clock::now();

    for (int gen = 0; gen < 100; gen++){
        // Force corners to stay active (AoC 2015 Day 18 Part 2 rules)
        boardState[0][0] = true;
        boardState[rows-1][0] = true;
        boardState[rows-1][cols-1] = true;
        boardState[0][cols-1] = true;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                int count = 0;
                
                // Optimized boundary checks instead of try-catch
                for (const auto& d : deltas){
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        if (boardState[ni][nj]) {
                            count++;
                        }
                    }
                }

                if (boardState[i][j]){
                    tempState[i][j] = (count == 2 || count == 3);
                }
                else {
                    tempState[i][j] = (count == 3);
                }
            }
        }
        boardState = tempState;
    }
    boardState[0][0] = true;
    boardState[rows-1][0] = true;
    boardState[rows-1][cols-1] = true;
    boardState[0][cols-1] = true;

    auto end = std::chrono::high_resolution_clock::now();
    // --- END TIMING ---

    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            count += (boardState[i][j] ? 1 : 0);
        }
    }

    std::cout << "Result: " << count << "\n";
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken (Boundary Check): " << duration.count() << " ms\n";
}
