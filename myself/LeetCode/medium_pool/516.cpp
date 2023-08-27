#include <iostream>

#include <vector>
#include <string_view>

class Solution {
private:
    static int max(int a, int b) { return a > b ? a : b; }

public:
    int longestPalindromeSubseq(std::string_view s) {
        std::vector<int> dp(s.size(), 0);

        for(int i = 0; i < s.size(); ++i) {
            int diag = 0;
            int last = 0;

            for(int j = 0; j < s.size(); ++j) {
                const int past = dp[j];
                dp[j] = max(max(past, last), diag + static_cast<int>(s[i] == s[s.size() - j - 1]));
                diag = past;
                last = dp[j];
            }
        }

        return dp.back();
    }
};


int main() 
{
    std::cout << Solution().longestPalindromeSubseq("bbbaba") << std::endl;
    return 0;
}
