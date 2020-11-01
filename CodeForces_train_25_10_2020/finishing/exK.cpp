// Made by Max Bronnikov
#include <string.h>
#include <stdio.h>


using namespace std;
 

#define MAX_LIM 40000001
#define HALF_LIM 20000000


 
int main(){
    int counter[26];
    memset(counter, 0, 26*sizeof(int));

    int* sieve = new int[MAX_LIM];
    memset(sieve, 0, MAX_LIM*sizeof(int));
    
    sieve[1] = 1;
    for(int i = 2; i < HALF_LIM; ++i){
        if(sieve[i]){
            continue;
        }
        
        counter[0] = 1;

        for(int j = i + i; j < MAX_LIM; j += i){
            int mult = 0;
            while(true){
                ++counter[mult];
                if(counter[mult] == i){
                    counter[mult++] = 0;
                    continue;
                }
                break;
            }

            mult += 2;

            if(!sieve[j]){
                sieve[j] = mult;
            }else{
                sieve[j] *= mult;
            }
        }

        memset(counter, 0, 16*sizeof(int));
    }


    int T;
    scanf("%d", &T);

    while(T--){
        int t;
        scanf("%d", &t);
        if(sieve[t]){
            printf("%d\n", sieve[t]);
        }else{
            printf("Prime\n");
        }
    }

    delete[] sieve;
    

    return 0;
}

