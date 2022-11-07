#include <iostream>

#include <vector>

class Solution {
public:
    int trap(const std::vector<int>& height) {
        int square = 0;

        std::vector<int> next_max_height(height.size());
        next_max_height.back() = 0;
        for(int i = height.size() - 1; i > 0; --i)
        {
            next_max_height[i - 1] = height[i] > next_max_height[i] ? height[i] : next_max_height[i];
        }

        int prev_max_height = height.front();
        for(int i = 1; i < height.size(); ++i)
        {
            int border = next_max_height[i] > prev_max_height ? prev_max_height : next_max_height[i];
            
            square += height[i] < border ? border - height[i] : 0;
            
            prev_max_height = height[i] > prev_max_height ? height[i] : prev_max_height;
        }

        return square;
    }
};

int main()
{
    std::cout << Solution().trap({4,2,0,3,2,5}) << std::endl;
    return 0;
}