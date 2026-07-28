#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("test.txt");
    std::ofstream output("modifiedinput.txt");
    std::string line;
    
    while (getline(input, line))
    {
        for (char &c: line)
        {
            if (c == ',')
            {
                c = '\n';
            }
        }
        output << line;
    }
    
    output.close();
    input.close();
    
    std::ifstream modifiedinput("modifiedinput.txt");
    long long result = 0;
    
    while (getline(modifiedinput, line))
    {
        size_t dash = line.find('-');
        long long start = stoll(line.substr(0, dash));
        long long end = stoll(line.substr(dash + 1));
        std::string temp;
        
        for (long long i = start; i <= end; i++)
        {
            temp = std::to_string(i);
            int len = temp.length();
            if (len % 2 != 0)
            {
                continue;
            }
            else{
                if (temp.substr(0, len/2) == temp.substr(len/2))
                {
                    result += i;
                }
            }
        }
    }
    
    std::cout << "Part 1: " << result;
}
