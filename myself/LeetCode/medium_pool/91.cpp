#include <iostream>

#include <string>

class Solution {
public:
    int numDecodings(const std::string& s) {
        std::pair<int, int> dp = {1, 1};
        if(s.back() == '0')
        {
            dp.first = 0;
        }


        for(int i = s.size() - 2; i >= 0; --i)
        {
            // min possible value
            int count = dp.first;

            // check branching
            if(s[i] == '0')
            {
                count = 0;
            }
            else if((s[i + 1] - '0') + 10*(s[i] - '0') <= 26)
            {
                count += dp.second;
            }

            // shift memoizaited data
            dp.second = dp.first;
            dp.first = count;
        }

        return dp.first;
    }
};


int main()
{
    std::cout << Solution().numDecodings("10") << std::endl;
    return 0;
}