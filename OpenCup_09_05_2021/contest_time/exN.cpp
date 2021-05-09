// Made by Lina Veltman
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

int main()
{
    int from, to;
    std::cin >> from >> to;

    int new_from = from - 1;
    std::string str = "";
    for (int i = to - 1; i >= new_from; --i)
    {
        str += "9";
    }
    int num_zeros = (int) (to - str.size());
    while (num_zeros)
    {
        str += "0";
        --num_zeros;
    }
    if (from == 1)
    {
        num_zeros = (int) str.size();
        str = "1";
        while (num_zeros)
        {
            str += "0";
            --num_zeros;
        }
    }
    std::cout << str << std::endl;
    
    return 0;
}