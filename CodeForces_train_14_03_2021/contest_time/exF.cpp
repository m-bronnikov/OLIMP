// Made by Lina Veltman
#include <stdio.h>
#include <iostream>
#include <vector>
 
 
void isOneCyclicShift(std::string& a, std::string& b, int& n)
{
    std::vector<int> diffIndexes;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            diffIndexes.emplace_back(i);
        }
    }
    
    int sizeIndx = (int) diffIndexes.size();
    for (int j = 0; j < sizeIndx; ++j)
    {
        if (b[diffIndexes[j]] != a[diffIndexes[(j + 1) % sizeIndx]])
        {
            std::cout << "NO" << std::endl;
            return;
        }
    }
    std::cout << "YES" << std::endl;
}
 
 
int main()
{
    int t;
    std::cin >> t;
    while (t)
    {
        int n;
        std::string a, b;
        std::cin >> n >> a >> b;
        isOneCyclicShift(a, b, n);
        --t;
    }
    return 0;
}