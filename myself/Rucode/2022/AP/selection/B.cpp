#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matr(n, std::vector<int>(m));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            std::cin >> matr[i][j];
        }
    }

    for(int i = 0; i < m; ++i)
    {
        std::cout << matr[0][i];
        for(int j = 1; j < n; ++j)
        {
            std::cout << " " << matr[j][i];
        }
        std::cout << std::endl;
    }

    return 0;
}