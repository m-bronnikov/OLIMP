// Made by Lina Veltman
#include <stdio.h>
#include <iostream>
 
 
int main()
{
    int t;
    std::cin >> t;
    while (t)
    {
        int n, black, white;
        std::cin >> n >> black >> white;
 
        if ((black + white) >= n && black >= ((n >> 1) + 1) && white >= (n >> 1))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
           std::cout << "NO" << std::endl;
        }
        --t;
    }
    return 0;
}