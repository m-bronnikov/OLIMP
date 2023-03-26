#include <iostream>

using namespace std;

#include <vector>

class Solution {
private:
    void solve(int ij_start, vector<vector<int>>& matrix, int counter)
    {
        int n = matrix.size() - (ij_start << 1);
        int m = matrix.front().size() - (ij_start << 1);

        if(n < 1 || m < 1) {
            return;
        }

        // top
        for(int j = 0; j < m; ++j) {
            matrix[ij_start][ij_start + j] = ++counter;
        }

        // right
        for(int i = 1; i < n - 1; ++i) {
            matrix[ij_start + i][ij_start + m - 1] = ++counter;
        }

        // bottom
        if(n > 1) {
            for(int j = m - 1; j >= 0; --j) {
                matrix[ij_start + n - 1][ij_start + j] = ++counter;
            }
        }

        // left
        if(m > 1) {
            for(int i = n - 2; i > 0; --i) {
                matrix[ij_start + i][ij_start] = ++counter;
            }
        }

        // start new iteration for inner matrix
        solve(ij_start + 1, matrix, counter);
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        solve(0, matrix, 0);
        return matrix;
    }
};


int main()
{
    auto m = Solution().generateMatrix(4);

    for(auto& l : m) {
        for(int v : l) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}