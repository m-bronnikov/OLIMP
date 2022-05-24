#include <stdio.h>
#include <string.h>

#define alphabet_size 128

int lengthOfLongestSubstring(char* s){
    int idx_of_char[alphabet_size];
    for(int i = 0; i < alphabet_size; ++i)
    {
        idx_of_char[i] = -1;
    }

    int max_len = 0;
    int start = -1;

    for(int i = 0; s[i] != '\0'; ++i)
    {
        start = (idx_of_char[s[i]] > start) ? idx_of_char[s[i]] : start;

        int len = i - start;
        max_len = len > max_len ? len : max_len;

        idx_of_char[s[i]] = i;
    }

    return max_len;
}


int main()
{
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));

    return 0;
}
