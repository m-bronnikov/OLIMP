// Made by Bronnikov Max
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void DestroyA(char** A, uint8_t N){
    if(!N){
        return;
    }
    for(uint8_t i = 0; i < N; ++i){
        free(A[i]);
    }
    free(A);
}

int main(){
    uint16_t N, M, res = 0;
    uint8_t N2;
    char c;

    char** A;
    scanf("%"SCNu16" %"SCNu16"\n", &N, &M);
    N2 = (uint8_t)(N >> 1);
    if(N2){
        A = (char**) malloc(sizeof(char*)*(N2));
        for(uint8_t i = 0; i < N2; ++i){
            A[i] = (char*)malloc(sizeof(char)*M);
            for(uint16_t j = 0; j < M; ++j){
                scanf("%c", &A[i][j]);
            }
            scanf("%c", &c);
        }
    }

    if(N & 1){
        uint8_t M2 = (uint8_t)(M >> 1);
        char* mid = (char*) malloc(M2 * sizeof(char));
        for(uint8_t j = 0; j < M2; ++j){
            scanf("%c", &mid[j]);
        }
        if(M & 1){
            scanf("%c", &c);
            if(c != '8'){
                free(mid);
                DestroyA(A, N2);
                printf("-1\n");
                return 0;
            }
        }
        for(int16_t j = M2-1; j >= 0; --j){
            scanf("%c", &c);
            if((c == '7' && mid[j] == '7') || (c == '9' && mid[j] == '9') || (c == '6' && mid[j] == '6')){
                ++res;
            }else if((c == '8' && mid[j] == '8') || (c == '9' && mid[j] == '6') || (c == '6' && mid[j] == '9')){

            }else{
                free(mid);
                DestroyA(A, N2);
                printf("-1\n");
                return 0;
            }
        }
        free(mid);
        scanf("\n");

    }


    if(N2){
    for(int16_t i = N2 - 1; i >= 0; --i){
        for(int16_t j = M - 1; j >= 0; --j){
                scanf("%c", &c);
                if((c == '7' && A[i][j] == '7') || (c == '9' && A[i][j] == '9') || (c == '6' && A[i][j] == '6')){
                    ++res;
                }else if((c == '8' && A[i][j] == '8') || (c == '9' && A[i][j] == '6') || (c == '6' && A[i][j] == '9')){

                }else{
                    DestroyA(A, N2);
                    printf("-1\n");
                    return 0;
                }
            }
            scanf("%c", &c);
        }
        DestroyA(A, N2);
    }
    printf("%"PRIu16"\n", res);
    return 0;
}