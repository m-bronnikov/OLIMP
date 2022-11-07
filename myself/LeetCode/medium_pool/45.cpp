#include <iostream>

#include <vector>
#include <queue>

class Solution {
private:
    struct Frame
    {
        int idx = -1;
        int step = -1;
    };

public:
    int jump(const std::vector<int>& nums) {
        std::vector<char> visited(nums.size(), 0);
        std::queue<Frame> frames;

        visited[0] = 1;
        frames.push({0, 0});

        while(!frames.empty())
        {
            Frame current = frames.front();
            frames.pop();

            if(current.idx == nums.size() - 1)
            {
                return current.step;
            }

            int border = current.idx + nums[current.idx] + 1;
            border = border > nums.size() ? nums.size() : border;

            for(int i = current.idx; i < border; ++i)
            {
                if(visited[i])
                {
                    continue;
                }

                visited[i] = 1;
                frames.push({i, current.step + 1});
            }
        }

        return -1;
    }
};


int main()
{
    std::cout << Solution().jump({2, 3, 0, 1, 4}) << std::endl;
    return 0;
}