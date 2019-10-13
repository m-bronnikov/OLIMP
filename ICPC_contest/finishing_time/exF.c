#include <stdio.h>
#include <inttypes.h>
#include <math.h>



int main() {
    long long unsigned N, b, a;
    long long unsigned res;
    scanf("%llu", &N);
    a = b = N;
      if(!(N & 1)){
             a = N >> 1;
      } 
 if(!(N % 3)){
   printf("3");
   return 0;
   }
    
    if (!(N & 3)) {
    	printf("4");
        return 0;
    }
    
    long long unsigned sq = sqrt(N);
    
    
    for(res = 5; res <= sq; res+=2){
      if(!(N % res)){
        	b = res;
        	break;
        }
    }
 	
    printf("%llu", (b < a ? b : a));


    return 0;
}