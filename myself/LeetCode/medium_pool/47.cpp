#include <iostream>

#include <vector>
#include <array>

class Solution {
private:
    static constexpr int min_lim = -10;
    static constexpr int max_lim = +10;

    struct NumCount
    {
        int num = 0;
        int count = 0;
    };

    static std::vector<NumCount> count_nums(const std::vector<int>& nums)
    {
        std::array<int, max_lim - min_lim + 1> counter{0};

        for(int i = 0; i < nums.size(); ++i)
        {
            ++counter[nums[i] - min_lim];
        }

        std::vector<NumCount> nums_counts;
        for(int i = 0; i < counter.size(); ++i)
        {
            if(counter[i] > 0)
            {
                nums_counts.push_back({i + min_lim, counter[i]});
            }
        }

        return nums_counts;
    }

    static void recusive_fill(std::vector<std::vector<int>>& out, std::vector<int>& cand, std::vector<NumCount>& nums)
    {
        if(cand.size() == cand.capacity())
        {
            out.push_back(cand);
            return;
        }


        for(auto& val : nums)
        {
            if(!val.count) {
                continue;
            }

            cand.push_back(val.num);
            --val.count;

            recusive_fill(out, cand, nums);

            cand.pop_back();
            ++val.count;
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(const std::vector<int>& nums) {
        std::vector<NumCount> num_counts = count_nums(nums);

        std::vector<int> cand;
        cand.reserve(nums.size()); // must be equal to nums

        std::vector<std::vector<int>> out;
        recusive_fill(out, cand, num_counts);

        return out;
    }
};

int main()
{
    auto ans = Solution().permuteUnique({1, 2, 3});

    for(auto& line : ans)
    {
        for(auto n : line)
        {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}