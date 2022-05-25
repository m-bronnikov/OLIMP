#include <stdio.h>

#include <limits.h>

int reverse(int x)
{
    const int upper_limit_divided = INT_MAX / 10;
    const int lower_limit_divided = INT_MIN / 10;
    const int upper_limit = upper_limit_divided * 10;
    const int lower_limit = lower_limit_divided * 10;

    int y = 0;
    while(x)
    {
        int m = x;
        x /= 10;
        m -= x * 10;

        if(y < lower_limit_divided)
            return 0;
        if(y > upper_limit_divided)
            return 0;
        y *= 10;

        if(y == lower_limit && m < INT_MIN - lower_limit)
            return 0;
        if(y == upper_limit && m > INT_MAX - upper_limit)
            return 0;
        y += m;
    }

    return y;
}

int main()
{
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    printf("%d\n", reverse(120));

    return 0;
}