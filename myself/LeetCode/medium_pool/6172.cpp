#include <iostream>

#include <array>

// Constexpr solution:
/*
static constexpr int isPlindromicInBase(int num, int base)
{
    std::array<int, 32> repr{0};

    int i = 0;
    while(num)
    {
        repr[i++] = num % base;
        num /= base;
    }

    for(int j = 0; j < i; ++j)
    {
        if(repr[j] != repr[i - j - 1]){
            return 0;
        }
    }

    return 1;
}


template <int max_num>
static constexpr std::array<int, max_num> evalAnswer()
{
    std::array<int, max_num> vals{0};

    for(int i = 4; i < max_num; ++i)
    {
        int ans = 1;
        for(int b = 2; b < i - 1; ++b)
        {
            if(!isPlindromicInBase(i, b))
            {
                ans = 0;
                break;
            }
        }

        vals[i] = ans;
    }

    return vals;
}

class Solution {
private:
    static constexpr int max_num = 100001;
    static constexpr std::array<int, max_num> answer = evalAnswer<max_num>();

public:
    bool isStrictlyPalindromic(int n) {
        return answer[n];
    }
};
*/

// In-fact solution
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};

int main()
{
    for(int i = 0; i < 100001; ++i)
    {
        if(Solution().isStrictlyPalindromic(i))
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
