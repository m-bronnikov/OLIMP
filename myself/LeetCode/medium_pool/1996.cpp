#include <iostream>

#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfWeakCharacters(std::vector<std::vector<int>>& props) {
        // sort elements
        auto const cmp = [](const std::vector<int>& lhs, const std::vector<int>& rhs)
        {
            return lhs.front() > rhs.front();
        };
        std::sort(begin(props), end(props), cmp);

        int count = 0;
        int max_attack = 0;
        int next_max_attack = props[0].back();

        for(int i = 1; i < props.size(); ++i)
        {
            if(props[i - 1].front() > props[i].front())
            {
                max_attack = next_max_attack;
            }
            
            next_max_attack = next_max_attack > props[i].back() ? next_max_attack : props[i].back();

            if(props[i].back() < max_attack)
            {
                ++count;
            }
        }

        return count;
    }
};


int main()
{
    std::vector<std::vector<int>> vec = {{7,7}, {1,2}, {9,7}, {7,3}, {3,10}, {9,8}, {8,10}, {4,3}, {1,5}, {1,5}};
    std::cout << Solution().numberOfWeakCharacters(vec) << std::endl;
    return 0;
}