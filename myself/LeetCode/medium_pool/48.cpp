#include <iostream>

#include <vector>
#include <algorithm>

using matrix = std::vector<std::vector<int>>;

class Solution {
public:
    void rotate(matrix& matr) {
        const int size = matr.size();

        int step = size - 1;
        int starti = 0;

        auto get_val = [&starti, &matr](int i, int j) -> int&
        {
            return matr[i + starti][j + starti];
        };

        auto update = [&step](int& i, int& j)
        {
            std::swap(i, j);
            j = step - j;
        };

        for(starti = 0; step > 0; step -= 2, ++starti)
        {
            int i = 0;
            for(int k = 0; k < step; ++k)
            {
                int j = k;
                int val = get_val(i, j);

                // do a circle
                do{
                    update(i, j);
                    std::swap(get_val(i, j), val);
                } while(i != 0 || j != k);
            }
        }
    }
};

int main()
{
    matrix m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Solution().rotate(m);

    for(auto& line : m)
    {
        for(auto i : line)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}