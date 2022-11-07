#include <iostream>

#include <vector>
#include <array>

class Solution {
private:
    static constexpr int values_count = 41;

private:
    void collect_target_sum(std::vector<int>& stk, int min, int target, std::vector<std::vector<int>>& result, const std::array<char, values_count>& counts)
    {
        if(target == 0)
        {
            result.push_back(stk);
            return;
        }

        const int lim = target + 1 > values_count ? values_count : target + 1;
        for(int i = min; i < lim; ++i)
        {
            if(!counts[i]){
                continue;
            }

            stk.push_back(i);
            collect_target_sum(stk, i, target - i, result, counts);
            stk.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target) {
        std::array<char, values_count> counts{0};

        for(int i : candidates)
        {
            ++counts[i];
        }

        std::vector<std::vector<int>> result;
        std::vector<int> stk;
        collect_target_sum(stk, 0, target, result, counts);

        return result;
    }
};

int main()
{
    auto result = Solution().combinationSum({2, 3, 5}, 8);
    for(const auto& ans : result)
    {
        for(int i : ans)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}