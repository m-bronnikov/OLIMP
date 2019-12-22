// Made by Max Bronnikov

#include <stdio.h>
#include <inttypes.h>

int main(){
    char c = 'a';
    int num = 0;
    scanf("%d\n", &num);
    for(int i = 0; i < num; ++i){
        uint8_t sum = 0;
        while((c = getchar()) != '\n'){
            if(c == ' '){
                if(sum == 26){
                    putchar(' ');
                }else{
                    putchar(sum + 'a');
                }
                sum = 0;
            }else{
                sum += (uint8_t)(c - 'a');
            }
            if(sum >= 27){
                sum -= 27;
            }
        }
        if(sum == 26){
            putchar(' ');
        }else{
            putchar(sum + 'a');
        }
        sum = 0;
        putchar('\n');
    }
    return 0;
}