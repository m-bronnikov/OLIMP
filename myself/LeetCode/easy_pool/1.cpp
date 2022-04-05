#include <vector>
#include <iostream>

#include <algorithm>

using namespace std;


class Solution {
private:
    struct pair
    {
        int idx;
        int value;
    };


public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort values and save their idxs
        std::vector<pair> vals(nums.size());
        for(int i = 0; i < vals.size(); ++i)
        {
            vals[i] = {i, nums[i]};
        }

        auto const cmp = [](pair lhs, pair rhs) { return lhs.value < rhs.value; };
        std::sort(begin(vals), end(vals), cmp);

        int left_bound = 0;
        int right_bound = 1;

        int sum = vals[left_bound].value + vals[right_bound].value;
        while(sum < target && right_bound < vals.size() - 1)
        {
            sum = vals[left_bound].value + vals[++right_bound].value;
        }

        while(sum != target)
        {
            if(sum > target)
            {
                sum = vals[left_bound].value + vals[--right_bound].value;
            }

            if(sum < target)
            {
                sum = vals[++left_bound].value + vals[right_bound].value;
            }
        }

        return {vals[left_bound].idx, vals[right_bound].idx};
    }
};


int main()
{
    int target = 6;
    std::vector<int> vec = {3,2,4};

    auto ans = Solution().twoSum(vec, target);
    std::cout << ans.front() << ' ' << ans.back() << std::endl;

    return 0;
}
