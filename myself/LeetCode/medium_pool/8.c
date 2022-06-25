#include <stdio.h>

#include <stdbool.h>
#include <limits.h>

int to_digit(char c)
{
    return c - '0';
}

bool is_digit(char c)
{
    int digit = to_digit(c);
    if(digit >= 0 && digit <= 9) return true;
    return false;
}

int myAtoi(const char* s){
    // skip whitespaces
    while(*s == ' ') ++s;

    if(*s == '\0') return 0;

    int sign = 1;
    sign = (*s == '-') ? -1 : 1;
    s = (*s == '-' || *s == '+') ? s + 1 : s;

    int division_limit = INT_MIN / 10;
    int module_limit = INT_MIN - division_limit * 10;
    
    // calculate answer in negative representation
    int result = 0;
    while(is_digit(*s))
    {
        if(result < division_limit)
        {
            result = INT_MIN;
            break;
        }

        int digit = -to_digit(*s);

        if(result == division_limit && digit <= module_limit)
        {
            result = INT_MIN;
            break;
        }

        result = 10*result + digit;

        ++s;
    }

    if(sign == 1)
    {
        result = result == INT_MIN ? INT_MAX : -result;
    }

    return result;
}


int main()
{
    printf("%d\n", myAtoi(".423  h"));
    return 0;    
}
