#include <iostream>
using namespace std;

#include <vector>

// one-pass solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int l_b = 0;
        int r_b = nums.size() - 1;

        while(i <= r_b) {
            if(nums[i] == 1) {
                ++i;
                continue;
            }

            if(nums[i] == 0) {
                std::swap(nums[i++], nums[l_b++]);
                continue;
            }

            if(nums[i] == 2) {
                std::swap(nums[i], nums[r_b--]);
            }
        }
    }
};

int main()
{
    std::vector<int> arr = {2, 0, 2, 1, 1, 0};
    Solution().sortColors(arr);
    for(int v : arr) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}