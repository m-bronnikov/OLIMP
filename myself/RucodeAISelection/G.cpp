#include <iostream>

int main()
{
    constexpr int edges = 6;

    int n, b, c;
    std::cin >> n >> b >> c;

    int max_m = 0;
    int max_idx = 0;
    for(int i = 1; i <= n; ++i)
    {
        int k, a, f;
        std::cin >> k >> a >> f;

        int m = k * (edges + 1 - a) * f;
        if(m > max_m)
        {
            max_m = m;
            max_idx = i;
        }
    }

    std::cout << max_idx << std::endl;

    return 0;
}