#include <iostream>

#include <vector>
#include <algorithm>


int binsearch_upper_bound(int* arr, int size, int elem)
{
    int l = 0;
    int r = size;

    while(l < r)
    {
        int m = (l + r) >> 1;

        if(arr[m] <= elem)
            l = m + 1;
        else
            r = m;
    }

    return l;
}



bool remove_more_than_2_dups(std::vector<int>& sorted){
    if(sorted.size() < 2)
        return false;

    bool zeros_triplet_exist = false;

    unsigned new_size = 2;
    for(unsigned i = 2; i < sorted.size(); ++i)
    {
        int zero_check = sorted[new_size - 2] | sorted[new_size - 1] | sorted[i];
        zeros_triplet_exist = zeros_triplet_exist || (zero_check == 0);


        if(sorted[new_size - 1] == sorted[new_size - 2] && sorted[new_size - 1] == sorted[i])
            continue;

        sorted[new_size++] = sorted[i];
    }

    sorted.resize(new_size);

    return zeros_triplet_exist;
}



class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;

        std::sort(begin(nums), end(nums));
        if(remove_more_than_2_dups(nums))
        {
            result.push_back({0, 0, 0});
        }

        int nums_size = nums.size();

        if(nums_size < 3)
            return result;
        

        for(int i = 0; i < nums_size - 2; ++i)
        {
            if(nums[i] >= 0)
                break;

            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            // cache k to speed up search
            int k = nums_size;

            for(int j = i + 1; j < nums_size - 1; ++j)
            {
                if(nums[i] + nums[j] > 0)
                    break;

                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int required_element = -nums[i] - nums[j];

                // search space [l, r)
                int l = j + 2;
                int r = k;

                // find k
                k = binsearch_upper_bound(nums.data() + l, r - l, required_element) + l;

                // '- 1' because result of upper bound is next element after required
                if(nums[k - 1] != required_element)
                {
                    continue;
                }


                result.push_back({nums[i], nums[j], nums[k - 1]});
            }
        }
        
        return result;
    }
};

int main()
{
    std::vector<int> arr = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

    std::vector<int> sorted = {-2, -1, 1, 2};
    std::cout << binsearch_upper_bound(sorted.data(), sorted.size(), 1) << std::endl;

    auto result = Solution().threeSum(arr);

    for(auto const& res : result)
    {
        std::cout << res[0] << " | " << res[1] << " | " << res[2] << std::endl;
    }

    return 0;
}