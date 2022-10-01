#include <iostream>

#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& str) {
        std::vector<std::pair<int, int>> segs;
        
        stack<int> stk;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == '(')
            {
                stk.emplace(i);
                continue;
            }

            if(stk.empty())
            {
                continue;
            }

            const int l = stk.top();
            stk.pop();

            while(!segs.empty() && l < segs.back().first)
            {
                segs.pop_back();
            }

            segs.push_back({l, i});
        }

        if(segs.empty())
        {
            return 0;
        }

        int j = 0;
        for(int i = 1; i < segs.size(); ++i)
        {
            const auto prev = segs[j];
            const auto next = segs[i];

            if(next.first == prev.second + 1)
            {
                segs[j].second = next.second;
                continue;
            }

            segs[++j] = segs[i];
        }
        segs.resize(j + 1);

        int max_len = 0;
        for(const auto& seg : segs)
        {
            const int len = seg.second - seg.first;
            max_len = len > max_len ? len : max_len;
        }

        return max_len + 1;
    }
};

int main()
{
    std::cout << Solution().longestValidParentheses("())((((())(") << std::endl;

    return 0;
}
