//Made by Max Bronnikov

// Task F about Gilberts hotel

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MODULO 1000000007

int main(){
  int32_t Q, x, g, buzy = 0;
  uint8_t n;

  scanf("%"SCNd32, &Q);
  int32_t* Groupes = (int32_t*)malloc(sizeof(int32_t) * (Q));

  for(int32_t i = 0; i < Q; ++i){
    scanf("%"SCNu8, &n);
    
    switch (n)
    {
    case 1:
      scanf("%"SCNd32, &Groupes[buzy++]);
      break;

    case 2:
      scanf("%"SCNd32" %"SCNd32, &g, &x);
      --x;
      --g;

      if(g > 0 && !Groupes[g]){
        x<<=1;
        ++x;
      }


      for(int32_t j = g+1; j < buzy; ++j){
        if(Groupes[j]){
          x+=Groupes[j];
        }else{
          x<<=1;
        }

        if(x >= MODULO){
          x-=MODULO;
        }
      }
      
      printf("%"PRId32"\n", x);
      break;

    case 3:
      scanf("%"SCNd32, &x);

      int32_t j = buzy - 1;
      for(j = buzy-1; j >= 0; --j){
        if(Groupes[j]){
          if(x > Groupes[j]){
            x-=Groupes[j];
          }else{
            break;
          }
        }else{
          if(x & 1){
            break;
          }else{
            x>>=1;
          }
        }
      }

      printf("%"PRId32"\n", ++j);
      break;
    
    default:
      printf("Error\n");
      return 1;
    }
  }

  return 0;
}