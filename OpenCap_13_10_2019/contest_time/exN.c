#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mgets()
{
/*очистка буфера ввода */
fflush(stdin);

    int i, k = getchar();

    /* Возвращаем NULL если ничего не введено */
    if (k == EOF)
        return;

    /* Считываем и копируем в буфер символы пока не достигнем конца строки или файла */
    for (i = 0; k != EOF && k != '\n'; ++i) {
        k = getchar();

        /* При обнаружении ошибки результирующий буфер непригоден */
        if (k == EOF && !feof(stdin))
        return;
    }
}

uint8_t getnum(char c){
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7': 
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return 0;
    }
}

bool GetAns(){
    uint8_t mod7 = 0;
    char c = getchar();
    if(c == '7'){
        mgets();
        return true;
    }
    mod7 = getnum(c);
    mod7 = mod7 > 7 ? mod7 - 7 : mod7;
    while((c = getchar()) >= '0' && c <= '9'){
        if(c == '7'){
            mgets();
            return true;
        }
        mod7*=3;
        mod7+=getnum(c);
        if(mod7 > 20){
            mod7 -= 21;
        }else if(mod7 > 13){
            mod7 -= 14;
        }else if(mod7 > 6){
            mod7 -= 7;
        }
    }
    if(mod7){
        return false;
    }
    return true;
}

int main(){
    uint8_t T;
    scanf("%"SCNu8"\n", &T);
    for(uint8_t i = 0; i < T; ++i){
        if(GetAns()){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    return 0;
}