#include <iostream>

#include <vector>

class Solution {
private:
    static void recusive_fill(std::vector<std::vector<int>>& out, std::vector<int>& cand, int mask, const std::vector<int>& nums)
    {
        if(cand.size() == nums.size())
        {
            out.push_back(cand);
            return;
        }

        int check_bit = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!(mask & check_bit))
            {
                mask ^= check_bit;
                cand.push_back(nums[i]);
                recusive_fill(out, cand, mask, nums);
                cand.pop_back();
                mask ^= check_bit;
            }

            check_bit <<= 1;
        }
    }

public:
    std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
        std::vector<std::vector<int>> out;
        out.reserve(124); // 6!

        std::vector<int> cand;
        cand.reserve(nums.size());
        recusive_fill(out, cand, 0, nums);

        return out;
    }
};

int main()
{
    auto ans = Solution().permute({1, 2, 4});
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