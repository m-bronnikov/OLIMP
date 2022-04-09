#include <stdbool.h>
#include <stdio.h>


bool isPalindrome(int x){
    if(x < 0)
        return false;

    long long copy = x;

    long long reversed = 0;
    while(copy)
    {
        reversed *= 10;
        reversed += copy % 10;
        copy /= 10;
    }

    return x == reversed;
}


int main()
{
    printf("%d\n", isPalindrome(-121));

    return 0;
}