#include <iostream>

#include <vector>
#include <algorithm>

using table = std::vector<std::vector<int>>;


class Solution {
public:
    table fourSum(std::vector<int>& nums, int target) {        
        const int size = nums.size();
        if(size < 4) return {};      
        
        std::sort(begin(nums), end(nums));
        
        table result;
        const int avg = target >> 2;
        for(int a = 0; a < size; ++a)
        {
            if(nums[a] > avg) break;
            
            if(a > 0 && nums[a] == nums[a - 1])
            {
                continue;
            }

            for(int b = a + 1; b < size; ++b)
            {
                if(b > a + 1 && nums[b] == nums[b - 1])
                {
                    continue;
                }

                // use 2 pointers to evaluate result
                int c = b + 1;
                int d = size - 1;
                while(c < d)
                {
                    if(c > b + 1 && nums[c] == nums[c - 1])
                    {
                        ++c;
                        continue;
                    }

                    if(d < size - 1 && nums[d] == nums[d + 1])
                    {
                        --d;
                        continue;
                    }

                    long long cand = static_cast<long long>(nums[a]) + nums[b] + nums[c] + nums[d];


                    if(cand == target)
                    {
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                    }

                    if(cand < target)
                    {
                        ++c;
                        continue;
                    }

                    --d;
                }
            }
        }

        return result;
    }
};

int main()
{
    std::vector<int> arr = {1, 0, -1, 0, -2, 2};
    // std::vector<int> arr = {0, 0, 0, 0, 5, 0, 0, 0, 0, 4, 2, 2, 4, 3, 2, 4, 2, 4, 2, 4, 4, 4, 2, 2, 2, 4};
    table result = Solution().fourSum(arr, 0);

    for(auto const& res : result)
    {
        std::cout << res[0] << " | " << res[1] << " | " << res[2] << " | " << res[3] << std::endl;
    }

    return 0;
}
