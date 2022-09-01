#include <iostream>

#include <vector>

class Solution {
private:
    using Access = char;
    using WaterMap = std::vector<std::vector<Access>>;

    template<Access mask>
    void propagate_water(int i, int j, WaterMap& memo, const std::vector<std::vector<int>>& space)
    {
        // skip if visited
        if(memo[i][j] & mask)
        {
            return;
        }

        // set water
        memo[i][j] |= mask;

        const int n = space.size();
        const int m = space.front().size();

        // pass water to higher positions
        if(i > 0 && space[i][j] <= space[i - 1][j]){
            propagate_water<mask>(i - 1, j, memo, space);
        }

        if(i < n - 1 && space[i][j] <= space[i + 1][j]){
            propagate_water<mask>(i + 1, j, memo, space);
        }

        if(j > 0 && space[i][j] <= space[i][j - 1]){
            propagate_water<mask>(i, j - 1, memo, space);

        }

        if(j < m - 1 && space[i][j] <= space[i][j + 1]){
            propagate_water<mask>(i, j + 1, memo, space);
        }
    }

    void fill_water(WaterMap& memo, const std::vector<std::vector<int>>& space)
    {
        const int n = space.size();
        const int m = space.front().size();

        static constexpr Access pacific_mask = 0x01;
        static constexpr Access atlantic_mask = 0x10;

        for(int i = 0; i < n; ++i)
        {
            propagate_water<pacific_mask>(i, 0, memo, space);
            propagate_water<atlantic_mask>(i, m - 1, memo, space);   
        }

        for(int j = 0; j < m; ++j)
        {
            propagate_water<pacific_mask>(0, j, memo, space);
            propagate_water<atlantic_mask>(n - 1, j, memo, space);   
        }
    }

public:
    std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>>& space) {
        const int n = space.size();
        const int m = space.front().size();

        WaterMap memo(n, std::vector<Access>(m, 0));
        fill_water(memo, space);

        std::vector<std::vector<int>> result;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                static constexpr Access both_oceans_mask = 0x11;

                if(memo[i][j] == both_oceans_mask){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};


int main()
{
    std::vector<std::vector<int>> space = {{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1}, {6,7,1,4,5}, {5,1,1,2,4}};
    auto const res = Solution().pacificAtlantic(space);

    for(auto const& ans : res){
        std::cout << ans.front() << " " << ans.back() << std::endl;
    }

    return 0;
}