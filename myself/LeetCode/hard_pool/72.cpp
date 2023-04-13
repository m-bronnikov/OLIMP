#include <iostream>

using namespace std;

#include <string_view>
#include <vector>

class Solution {
public:
    int minDistance(std::string_view word1, std::string_view word2) {
        if(word1.size() < word2.size()) {
            std::swap(word1, word2);
        }

        std::vector<int> dp1(word1.size() + 1);
        std::vector<int> dp2(word1.size() + 1);

        for(int i = 0; i < dp1.size(); ++i) {
            dp1[i] = i;
        }

        for(int i = 1; i <= word2.size(); ++i) {
            dp2[0] = i;

            for(int j = 1; j < dp2.size(); ++j) {
                dp2[j] = min(dp2[j - 1] + 1, min(dp1[j] + 1, dp1[j - 1] + static_cast<int>(word1[j - 1] != word2[i - 1])));
            }

            dp1.swap(dp2);
        }

        return dp1.back();
    }
};

int main() {
    std::cout << Solution().minDistance("sea", "sun") << std::endl;
    return 0;
}
