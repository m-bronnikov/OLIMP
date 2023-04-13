#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid.front().size();

        vector<long long> dp(n);
        dp.back() = grid.back().back() ^ 1;
        for(int i = n - 2; i >= 0; --i) {
            if(grid.back()[i] == 1) {
                dp[i] = 0;
                continue;
            }

            dp[i] = dp[i + 1];
        }

        for(int i = m - 2; i >= 0; --i) {
            if(grid[i].back() == 1) {
                dp.back() = 0;
            }

            for (int j = n - 2; j >= 0; --j) {
                if(grid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }

                dp[j] += dp[j + 1];
            }
        }

        return dp[0];
    }
};


int main() 
{
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};

    std::cout << Solution().uniquePathsWithObstacles(grid) << std::endl;

    return 0;
}