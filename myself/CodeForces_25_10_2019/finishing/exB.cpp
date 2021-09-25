// Made by Bronnikov Max
#include <stdio.h>
#include <iostream>
 
short num(char a){
    switch(a){
        case '0':{
            return 0;
        }
        case '1':{
            return 1;
        }
        case '2':{
            return 2;
        }
        case '3':{
            return 3;
        }
        case '4':{
            return 4;
        }
        case '5':{
            return 5;
        }
        case '6':{
            return 6;
        }
        case '7':{
            return 7;
        }
        case '8':{
            return 8;
        }
        case '9':{
            return 9;
        }
    }
    return 0;
}
 
int main(){
    short x, y = 0;
    char a = getchar();
    x = num(a);
    while((a = getchar()) >= '0' && a <= '9'){
        y = num(a);
        x*=10;
        x+=y;
        x %= 97;
    }
    if(x){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}