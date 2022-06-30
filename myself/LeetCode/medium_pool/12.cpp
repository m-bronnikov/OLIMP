#include <iostream>

#include <array>

struct LatinNum
{
    char letter;
    int number;
};

static constexpr std::array<LatinNum, 7> reverse_sorted_numbers = {{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
}};

class Solution {
public:
    std::string intToRoman(int num) {
        std::string result;

        for(int i = reverse_sorted_numbers.size() - 1; i >= 0; --i)
        {
            LatinNum latin = reverse_sorted_numbers[i];

            while (num >= latin.number)
            {
                result.push_back(latin.letter);
                num -= latin.number;
            }

            if(i == 0)
                break;

            LatinNum next_latin = reverse_sorted_numbers[((i - 1) >> 1) << 1];
            int number_before = latin.number - next_latin.number;

            if(num >= number_before)
            {
                result.push_back(next_latin.letter);
                result.push_back(latin.letter);
                num -= number_before;
            }
        }

        return result;
    }
};

int main()
{
    std::cout << Solution().intToRoman(58) << std::endl;
    return 0;
}