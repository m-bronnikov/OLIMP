#include <stdio.h>


int letter_to_int(char c){
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        break;
    }

    return 0;
}

int letter_value_from_pattern(char c, char next_c)
{
    int cur = letter_to_int(c);
    int next = letter_to_int(next_c);

    if(cur == 1 && next == 5)
        return -cur;
    if(cur == 1 && next == 10)
        return -cur;
    if(cur == 10 && next == 50)
        return -cur;
    if(cur == 10 && next == 100)
        return -cur;
    if(cur == 100 && next == 500)
        return -cur;
    if(cur == 100 && next == 1000)
        return -cur;   

    return cur;
}

int romanToInt(char *s){
    int arabian = 0;
    
    for(char c = *s; c != '\0'; c = *(++s))
    {
        char next = *(s + 1);
        arabian += letter_value_from_pattern(c, next);
    }

    return arabian;
}


int main()
{
    char str[16];
    scanf("%s", str);

    int arabian = romanToInt(str);
    printf("%d\n", arabian);

    return 0;
}
