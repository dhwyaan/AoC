#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
    std::ifstream input("input.txt");
    std::string line;
    int total = 0;
    while (getline(input, line)){
        int len = line.length();
        int left = 0;
        int right = 0;
        int maxL;
    
        for (int i = 0; i < len - 1; i ++)
        {
            if (left < line[i] - '0'){
                left = line[i] - '0';
                maxL = i;
            }
        }
        
        for (int j = maxL + 1; j < len; j++)
        {
            right = std::max(right, line[j] - '0');
        }
        
        std::cout << left * 10 + right << '\n';
        total += left * 10 + right;
    }
    
    std::cout << total;
}
