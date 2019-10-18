#include <iostream>
#include <inttypes.h>

#define MODULO 1000000007
#define MODULO2 2000000014
#define MODULO3 3000000021
#define MODULO4 4000000028

int main(){
    uint32_t N;
    uint64_t a;
    uint32_t max1 = 0, max2 = 0; // max2 max1
    std::cin >> N >> a;
    ++N;
    for(uint32_t i = 1; i < N; ++i){
        a*=5;
        a%=MODULO;
        
        /*if(a >= MODULO4){
            a-=MODULO4;
        }else if(a >= MODULO3){
            a-=MODULO3;
        }else if(a >= MODULO2){
            a-=MODULO2;
        }else if(a >= MODULO){
            a-=MODULO;
        }*/
        if(a > max2){
            if(a > max1){
                max2 = max1;
                max1 = a;
            }else{
                max2 = a;
            }
        }
    }
    std::cout << max2 << ' ' << max1 << std::endl;
    return 0;
}