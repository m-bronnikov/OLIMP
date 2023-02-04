#include <iostream>

#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    long long maxScore(const std::vector<int>& num1, const std::vector<int>& num2, int k) {
        std::vector<int> idx(num2.size());
        for(int i = 0; i < idx.size(); ++i)
        {
            idx[i] = i;
        }

        auto const cmp = [&num2](int li, int ri) { return num2[li] < num2[ri]; };
        std::sort(begin(idx), end(idx), cmp);
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> max_values;
        long long max_sum = 0;
        {
            for(int i = idx.size() - k; i < idx.size(); ++i)
            {
                max_values.push(num1[idx[i]]);
                max_sum += num1[idx[i]];
            }
        }
        long long max_score = max_sum * num2[idx[idx.size() - k]];

        idx.resize(idx.size() - k);
        while(!idx.empty())
        {
            // pop back value from stack 
            int i = idx.back();
            idx.pop_back();

            int less_val = max_values.top();
            int curr_val = num1[i];

            if(less_val >= curr_val)
            {
                continue;
            }

            max_values.pop();
            max_values.push(curr_val);

            max_sum += curr_val - less_val;

            long long score = max_sum * num2[i];
            max_score = max_score > score ? max_score : score;
        }

        return max_score;
    }
};

int main()
{
    std::vector<int> num1 = {4, 5, 6, 7};
    std::vector<int> num2 = {8, 9, 8, 1};

    std::cout << Solution().maxScore(num1, num2, 2) << std::endl;

    return 0;
}