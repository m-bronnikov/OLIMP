#include <iostream>
using namespace std;

#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count_current = 0;
        int current = nums.front();

        int i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            if (current == nums[j]) {
                ++count_current;
            } else {
                current = nums[j];
                count_current = 1;
            }

            nums[i] = nums[j];
            i = count_current < 3 ? i + 1 : i;
        }

        return i;
    }
};


int main()
{
    std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    std::cout << Solution().removeDuplicates(nums) << std::endl;

    return 0;
}