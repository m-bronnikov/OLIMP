// Made by Lina Veltman
#include <stdio.h>
#include <iostream>


int main()
{
    int n;
    std::string str;
    
    std::cin >> n;
    std::cin >> str;
    
    int num = 1;
    int strNum = 1;

    for (int i = 0; i < str.size(); ++i, ++num)
    {
        if (num < 10)
        {
            if (str[i] - '0' != num)
            {
                std::cout << num << std::endl;
                return 0;
            }
        }
        else if (num > 9 && num < 100)
        {
            strNum = (str[i] - '0') * 10 + (str[i + 1] - '0');
            ++i;
            if (strNum != num)
            {
                std::cout << num << std::endl;
                return 0;
            }
        }
    }
    std::cout << num << std::endl;
    return 0;
}