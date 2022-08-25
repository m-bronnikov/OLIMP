#include <iostream>

#include <limits>

class Solution {
private:
    unsigned abs(int num) { return num < 0 ? -static_cast<unsigned>(num) : static_cast<unsigned>(num); }

public:
    int divide(const int dividend, const int divisor) {
        // catch exceptional border case
        static constexpr int min_int = std::numeric_limits<int>::min();
        static constexpr int max_int = std::numeric_limits<int>::max();
        if(dividend == min_int && divisor == -1)
        {
            return max_int;
        }

        // check does sign bit of divisor is equal to bit of dividend
        const int sign = ((dividend ^ divisor) >> 31) ? -1 : +1;

        // let's compute in terms of unsigned numbers
        unsigned numerator = abs(dividend);
        unsigned denumerator = abs(divisor);

        // compute amount of bits in divisor
        int divisor_bits = 0;
        for(unsigned n = denumerator; n != 0; n >>= 1) ++divisor_bits;

        // prepare denumenator to long division and define number of digits in binary result
        const int shift = 32 - divisor_bits;
        denumerator <<= shift;
        int digits = shift + 1; // include current

        // divide
        unsigned result = 0;
        while(digits--)
        {
            result <<= 1;            
            if(numerator >= denumerator)
            {
                numerator -= denumerator;
                result |= 1;
            }
            denumerator >>= 1;
        }

        // apply sign
        return static_cast<int>(sign == 1 ? result : -result);
    }
};


int main()
{
    std::cout << Solution().divide(4323, 23) << std::endl;
    return 0;
}
