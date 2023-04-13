#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int j = 1; j < grid.front().size(); ++j) {
            grid.front()[j] += grid.front()[j - 1];
        }

        for(int i = 1; i < grid.size(); ++i) {
            grid[i].front() += grid[i - 1].front();

            for(int j = 1; j < grid[i].size(); ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid.back().back();
    }
};

int main() {
    vector<vector<int>> vec = {{1,3,1},{1,5,1},{4,2,1}};

    std::cout << Solution().minPathSum(vec) << std::endl;

    return 0;
}
