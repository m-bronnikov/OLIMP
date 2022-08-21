#include <iostream>

#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        const int n = nums1.size();

        std::unordered_map<int, int> sumcnt;
        for(int i = 0; i < n; ++i)
        {
            int ival = nums1[i];
            for(int j = 0; j < n; ++j)
            {
                ++sumcnt[ival + nums2[j]];
            }
        }
        
        int counter = 0;
        for(int i = 0; i < n; ++i)
        {
            int ival = nums3[i];
            for(int j = 0; j < n; ++j)
            {
                counter += sumcnt[-ival - nums4[j]];
            }
        }

        return counter;
    }
};



int main(){
    std::vector<int> arr1 = {1, 1, -1, -1};
    std::vector<int> arr2 = {-1, -1, 1, 1};
    std::vector<int> arr3 = {1, -1, 0, -1};
    std::vector<int> arr4 = {1, 1, -1, 1};

    int result = Solution().fourSumCount(arr1, arr2, arr3, arr4);
    std::cout << result << std::endl;

    return 0;
}