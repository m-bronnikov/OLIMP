#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int max(int x, int y) { return x > y ? x : y; } 
int min(int x, int y) { return x < y ? x : y; }

char* longestPalindrome(char* s){
    // compute len of input string
    int size = 0;
    while(s[size] != '\0') ++size;

    if(size == 0)
        return "";

    // Manaker's algorithm

    int* data = (int*) malloc(sizeof(int) * (size << 1));

    // d1 searches radius of centers for palindroms of odd lenght
    // places of centres enumerated as:
    // str: | a b c e c b |
    // idx: | 0 1 2 3 4 5 |
    int* d1 = data;
    d1[0] = 0;

    // d2 searches radius of centers for palindroms of even lenght
    // places of centres enumerated as:
    // str: | a b c e c b |
    // idx: |0 1 2 3 4 5  |
    int* d2 = data + size;
    d2[0] = 0;

    // keep in memory centers of most right defined palindrom
    int odd_rigth_c = 0;
    int even_rigth_c = 0;

    // first found max palindrom's radius
    int max_d = 0;

    for(int i = 1; i < size; ++i)
    {
        // define start d1[i] for computations
        {
            int r1 = odd_rigth_c + d1[odd_rigth_c];
            d1[i] = r1 > i ? min(d1[(odd_rigth_c << 1) - i], r1 - i) : 0;
        }

        // define start d2[i] for computations
        {
            int r2 = even_rigth_c + d2[even_rigth_c];
            d2[i] = r2 > i ? min(d2[(even_rigth_c << 1) - i], r2 - i) : 0;
        }

        // compute d1 (note '++d1[i]' always true)
        while(++d1[i] && i - d1[i] >= 0 && i + d1[i] < size && s[i - d1[i]] == s[i + d1[i]]);
        --d1[i]; // decrease for d1[i] which makes condition above false

        // compute d2
        while(i - d2[i] - 1 >= 0 && i + d2[i] < size && s[i - d2[i] - 1] == s[i + d2[i]])
            ++d2[i];

        // update centres if needed
        odd_rigth_c = (i + d1[i]) > (odd_rigth_c + d1[odd_rigth_c]) ? i : odd_rigth_c;
        even_rigth_c = (i + d2[i]) > (even_rigth_c + d2[even_rigth_c]) ? i : even_rigth_c;

        // update max radius
        max_d = max(max(max_d, d1[i]), d2[i]);
    }

    // find longest palindrom
    for(int i = 0; i < size; ++i)
    {
        if(d1[i] == max_d)
        {
            free(data);

            // return substring
            int len = (max_d << 1) + 1;
            int start = i - max_d;
            s[start + len] = '\0';
            return &s[start];
        }
    }

    for(int i = 1; i < size; ++i)
    {
        if(d2[i] == max_d)
        {
            free(data);

            // return substring
            int len = (max_d << 1);
            int start = i - max_d;
            s[start + len] = '\0';
            return &s[start];
        }
    }

    // impossible case
    free(data);
    return "";
}


int main()
{
    char* str = (char*) malloc(10);

    memcpy(str, "salas", sizeof("salas"));
    printf("1: %s\n", longestPalindrome(str));

    memcpy(str, "hello", sizeof("hello"));
    printf("2: %s\n", longestPalindrome(str));

    memcpy(str, "", sizeof(""));
    printf("3: %s\n", longestPalindrome(str));

    memcpy(str, "not palindrome", sizeof("not palindrome"));
    printf("3: %s\n", longestPalindrome(str));

    free(str);
    return 0;
}