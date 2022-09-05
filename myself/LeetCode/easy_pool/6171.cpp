#include <iostream>

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool findSubarrays(const std::vector<int>& nums) 
    {
        const int sums_count = nums.size() - 1;

        std::unordered_set<int> sum2idx;
        for(int i = 0; i < sums_count; ++i)
        {
            int sum = nums[i] + nums[i + 1];
            if(sum2idx.count(sum))
            {
                return true;
            }

            sum2idx.insert(sum);
        }

        return false;
    }
};

int main()
{
    std::vector<int> nums = {2, 4, 2};

    std::cout << Solution().findSubarrays(nums) << std::endl;

    return 0;
}