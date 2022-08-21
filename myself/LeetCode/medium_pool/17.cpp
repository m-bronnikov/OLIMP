#include <iostream>

#include <array>
#include <vector>
#include <string_view>

static constexpr std::array<std::string_view, 10> digits_codes = {
    "",         // 0 - nothing
    "",         // 1 - nothing
    "abc",      // 2
    "def",      // 3
    "ghi",      // 4
    "jkl",      // 5
    "mno",      // 6
    "pqrs",     // 7
    "tuv",      // 8
    "wxyz"      // 9
};

class Solution {
public:
    std::vector<std::string> letterCombinations(const std::string& digits) {
        constexpr auto digit_to_num = [](char c) { return static_cast<int>(c - '0'); };

        // length of each possible code
        const int code_len = digits.size();
        if(code_len == 0){
            return {};
        }

        // compute amount of different codes
        int invariants = 1;
        for(const char c : digits)
        {
            invariants *= digits_codes[digit_to_num(c)].size();
        }

        // allocate required amount of space
        std::vector<std::string> result(invariants, digits);

        // fill result table
        int acc = 1;
        for(int i = 0; i < code_len; ++i)
        {
            // define symbols for digit
            const int digit_num = digit_to_num(digits[i]);
            const int digit_chars = digits_codes[digit_num].size();

            // define row length
            const int in_row = acc;

            // update acc
            acc *= digit_chars;

            // define rows count
            const int rows = invariants / acc;

            // iterate
            for(int j = 0; j < rows; ++j)
            {
                for(int m = 0; m < digit_chars; ++m)
                {
                    for(int k = 0; k < in_row; ++k)
                    {
                        int idx = (j * digit_chars + m) * in_row + k;
                        result[idx][i] = digits_codes[digit_num][m];
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    auto ans =  Solution().letterCombinations("2329");

    for(const auto& str : ans)
    {
        std::cout << str << std::endl;
    }

    return 0;
}