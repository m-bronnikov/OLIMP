#include <iostream>
using namespace std;

#include <vector>

class Solution {
private:
    void solve(int ij_start, const vector<vector<int>>& matrix, vector<int>& result)
    {
        int n = matrix.size() - (ij_start << 1);
        int m = matrix.front().size() - (ij_start << 1);

        if(n < 1 || m < 1)
        {
            return;
        }

        // top
        for(int j = 0; j < m; ++j) {
            result.push_back(matrix[ij_start][ij_start + j]);
        }

        // right
        for(int i = 1; i < n - 1; ++i) {
            result.push_back(matrix[ij_start + i][ij_start + m - 1]);
        }

        // bottom
        if(n > 1)
        {
            for(int j = m - 1; j >= 0; --j) {
                result.push_back(matrix[ij_start + n - 1][ij_start + j]);
            }
        }

        // left
        if(m > 1)
        {
            for(int i = n - 2; i > 0; --i) {
                result.push_back(matrix[ij_start + i][ij_start]);
            }
        }
        solve(ij_start + 1, matrix, result);
    }

public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix)
    {
        vector<int> result;
        result.reserve(matrix.size() * matrix.front().size());
        solve(0, matrix, result);
        return result;
    }
};


int main()
{
    auto res = Solution().spiralOrder({{1,2,3},{4,5,6},{7,8,9}});
    for(int n : res)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}