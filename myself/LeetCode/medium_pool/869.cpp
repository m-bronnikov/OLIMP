#include <iostream>

#include <array>

namespace
{
    struct sorted_num
    {
        constexpr static sorted_num make_from(int num)
        {
            sorted_num result = {0};

            // decompose number to digits
            std::array<size_t, 10> digit_counter{0};
            while(num)
            {
                int digit = num;
                num /= 10;
                digit -= num * 10;

                ++digit_counter[digit];
                ++result.digits;
            }

            // use count sort to obtain sorted number
            // complexity: O(result.digits)
            for(size_t i = 0; i < digit_counter.size(); ++i)
            {
                for(size_t j = 0; j < digit_counter[i]; ++j)
                {
                    result.repr *= 10;
                    result.repr += i;
                }
            }

            return result;
        }

        bool operator==(sorted_num rhs) const
        {
            return repr == rhs.repr && digits == rhs.digits;
        }

        int repr;
        int digits;
    };
}

namespace compile_time
{
    template<int limit>
    constexpr int compute_pows_count(){
        int result = 0;
        for(int i = 1; i <= limit; i <<= 1)
        {
            ++result;
        }
        return result;
    }

    template<int count>
    constexpr std::array<sorted_num, count> compute_pows()
    {
        std::array<sorted_num, count> result{};

        int pow = 1;
        for(int i = 0; i < count; ++i)
        {
            result[i] = sorted_num::make_from(pow);
            pow <<= 1;
        }

        return result;
    }
}


class Solution {
private:
    static constexpr int pows_count = compile_time::compute_pows_count<1000000000>();
    static constexpr std::array<sorted_num, pows_count> pows = compile_time::compute_pows<pows_count>();

public:
    bool reorderedPowerOf2(int n) {
        const sorted_num reordered = sorted_num::make_from(n);

        // use linear search over all possible pows
        for(size_t i = 0; i < pows.size(); ++i)
        {
            if(reordered == pows[i])
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    std::cout << Solution().reorderedPowerOf2(125) << std::endl;
    return 0;
}