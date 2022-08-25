#include <iostream>

#include <limits>
#include <array>
#include <algorithm>

namespace compile_time {
    constexpr int compute_count_of_pows() {
        const int limit = std::numeric_limits<int>::max() / 3;
        
        int count = 1;
        int num = 1;
        while(num <= limit)
        {
            num *= 3;
            ++count;
        }

        return count;
    }

    template<int count_of_pows>
    constexpr std::array<int, count_of_pows> compute_pows() {
        std::array<int, count_of_pows> pows{1};

        int pow = 1;
        for(int i = 1; i < count_of_pows; ++i)
        {
            pow *= 3;
            pows[i] = pow;
        }

        return pows;
    }
}

class Solution {
private:
    // compile time constants
    static constexpr int count_of_pows = compile_time::compute_count_of_pows();
    static constexpr std::array<int, count_of_pows> pows_of_three = compile_time::compute_pows<count_of_pows>();
    
public:
    bool isPowerOfThree(int num) {
        if(num <= 0)
            return false;

        return std::binary_search(begin(pows_of_three), end(pows_of_three), num);
    }
};

int main()
{
    std::cout << Solution().isPowerOfThree(27) << std::endl;
    return 0;
}