#include <iostream>

#include <vector>

struct Solution
{
    int solution(const std::vector<int>& heights)
    {
        // init jump lenghts of each block with zero
        int blocks_count = heights.size();
        std::vector<int> lengths(blocks_count, 0);

        // compute left jump for each block and reflect in length
        int left_jump = 0;
        for(int i = 1; i < blocks_count; ++i)
        {
            if(heights[i - 1] >= heights[i])
            {
                ++left_jump;
                lengths[i] += left_jump;
                continue;
            }

            left_jump = 0;
        }

        // compute right jump for each block and reflect in length
        int right_jump = 0;
        for(int i = blocks_count - 1; i > 0; --i)
        {
            if(heights[i] >= heights[i - 1])
            {
                ++right_jump;
                lengths[i - 1] += right_jump;
                continue;
            }

            right_jump = 0;
        }

        // find max length
        int max_len = 0;
        for(int len : lengths)
        {
            max_len = len > max_len ? len : max_len;
        }

        return max_len + 1;
    }
};

int main()
{
    std::cout << Solution().solution({2, 6, 8, 5}) << std::endl;
    std::cout << Solution().solution({1, 5, 5, 2, 6}) << std::endl;
    std::cout << Solution().solution({1, 1}) << std::endl;
    return 0;
}