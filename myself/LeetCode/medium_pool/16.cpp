#include <iostream>

#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // let's search in sorted array
        std::sort(begin(nums), end(nums));

        const int nums_size = nums.size();

        // some initial result value
        int result = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums_size - 2; ++i)
        {
            // there is no negative value to produce target after nums[i]
            if(nums[i] >= target){
                break;
            }

            // solution is already found for values which starts from nums[i - 1], skip dups
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            // 2 pointers scan solution
            int j = i + 1;
            int k = nums_size - 1;
            while (k > j)
            {
                int to_check = nums[i] + nums[j] + nums[k];
                result = std::abs(result - target) < std::abs(to_check - target) ? result : to_check;
                
                to_check > target ? --k : ++j;
            }
        }

        return result;
    }
};

int main()
{
    std::vector<int> arr = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

    int result = Solution().threeSumClosest(arr, 0);
    std::cout << "solution: " << result << std::endl;

    return 0;
}
