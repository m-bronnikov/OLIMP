#include <stdio.h>

#include <stdlib.h>
#include <string.h>

int min(int x, int y) { return x > y ? y : x; }

// value not in alphabet to delim str from pattern in union string
const char delim = '#';

int strStr(const char* source, const char* pattern){
    const int source_len = strlen(source);
    const int pattern_len = strlen(pattern);
    const int len = pattern_len + source_len + 1; // +1 for delim

    // catch special case
    if(pattern_len == 0)
    {
        return 0;
    }

    // alloc single buffer for string and z-blocks
    void* allocated_data = malloc(len * (sizeof(char) + sizeof(short)));

    // hack: shift buffer by 1 left because 0th element is unused
    short* z_block = ((short*) allocated_data) - 1;

    // define str
    char* str = (char*) (z_block + len);

    // copy pattern to head
    memcpy(str, pattern, pattern_len * sizeof(char));

    // add terminal
    str[pattern_len] = delim;

    // copy source string to the tail: hack above provides additional space for null-terminal
    memcpy(str + pattern_len + 1, source, (source_len + 1) * sizeof(char)); // copy with null at the and

    // scanned interval
    int l = 0;
    int r = 0;

    // result
    int res_idx = -1;

    // main routine
    for(int i = 1; i < len; ++i)
    {
        // define initial value depending to scanned interval
        z_block[i] = i < r ? min(z_block[i - l], r - i) : 0;

        // calculate z-block for i
        while(i + z_block[i] < len && str[i + z_block[i]] == str[z_block[i]]){
            ++z_block[i];
        }

        // check pattern is found
        if(z_block[i] == pattern_len)
        {
            // it's impossible to find pattern until delim, so value is positive
            res_idx = i - pattern_len - 1; // -1 for delim
            break;
        }

        // update interval
        if(i + z_block[i] > r)
        {
            l = i;
            r = l + z_block[i];
        }
    }

    // free allocated memory and return result
    free(allocated_data);
    return res_idx;
}

int main(){
    const char* source = "hello";
    const char* pattern = "ll";

    printf("%d\n", strStr(source, pattern));
    return 0;
}
