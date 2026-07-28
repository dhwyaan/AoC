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

// PART 2
// #include <iostream>
// #include <fstream>
// #include <string>

// int main()
// {
//     std::ifstream input("input.txt");
//     std::string line;
//     long long total = 0;
//     while (getline(input, line)){
//         int len = line.length();
//         int max = 0;
//         int newStart = -1;
//         const int totalDigits = 12;
//         int remainDigits = totalDigits-1;
//         long long num = 0;
    
//         for (int i = 0; i < totalDigits; i++) //this loop counts the array up 0 to 11
//         {
//             for (int j = newStart + 1; j < len - remainDigits; j++) //this loop finds the largest num in range newStart+1 to len-remainDigits
//             {
//                 if (line[j] - '0' > max)
//                 {
//                     max = line[j] - '0';
//                     newStart = j;
//                 }
//             }
//             num *= 10;
//             num += max;
//             max = 0;
//             remainDigits--;
//         }
//         std::cout << num << '\n';
//         total += num;
//     }
    
//     std::cout << total;
// }
