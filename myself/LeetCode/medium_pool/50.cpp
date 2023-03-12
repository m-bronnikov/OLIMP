#include <iostream>

#include <limits>

class Solution {
    double bin_pow(double x, unsigned n)
    {
        double res = 1.0;
        double mult = x;

        while(n)
        {
            if(n & 1)
            {
                res *= mult;
            }

            n >>= 1;
            mult *= mult;
        }

        return res;
    }

public:
    double myPow(double x, int n) {
        if(n == std::numeric_limits<int>::min())
        {
            return 1.0 / bin_pow(x, -(n + 1)) / x;
        }

        if(n < 0)
        {
            return 1.0 / bin_pow(x, -n);
        }

        return bin_pow(x, n);
    }
};

int main()
{
    std::cout << Solution().myPow(1.232, 17) << std::endl;
    return 0;
}