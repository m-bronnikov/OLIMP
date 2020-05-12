// Made by Max Bronnikov
#include "stdio.h"


//using namespace std;

char shifting1(char c, unsigned shift){
    if(c + shift > 'z'){
        return c + shift - 26;
    }
    return c + shift;
}

char shifting2(char c, unsigned shift){
    if(c + shift > 'Z'){
        return c + shift - 26;
    }
    return c + shift;
}


int main(){
    unsigned shift;
    char c;
    scanf("%u", &shift);
    while(getchar() != '\n');
    shift %= 26;
    //printf("%u\n", shift);
    while((c = getchar()) != EOF){
        if(c <= 'z' && c >= 'a'){
            c = shifting1(c, shift);
        }
        if(c <= 'Z' && c >= 'A'){
            c = shifting2(c, shift);
        }
        putchar(c);
    }
    return 0;
}