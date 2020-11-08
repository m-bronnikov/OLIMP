// Made by Lina Veltman
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <istream>
#include <algorithm>


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    if (n == 1)
    {
        std::cout << arr[0] << std::endl;
    }
    std::sort(arr.begin(), arr.end());
    int sum = arr[0] + arr[n - 1];
    for (int i = 0, j = n - 1; i < j; ++i, --j)
    {
        sum = std::min(arr[i] + arr[j], sum);
    }
    std::cout << sum << std::endl;

    return 0;
}
