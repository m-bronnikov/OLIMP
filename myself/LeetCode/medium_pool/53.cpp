#include <iostream>
using namespace std;

#include <vector>
#include <limits>

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int max_score = std::numeric_limits<int>::min();
        int curr_score = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            curr_score += nums[i];
            max_score = curr_score > max_score ? curr_score : max_score;

            if(curr_score < 0) {
                curr_score = 0;
            }
        }

        return max_score;
    }
};

int main()
{
    std::cout << Solution().maxSubArray({-1, -5, -3}) << std::endl;

    return 0;
}