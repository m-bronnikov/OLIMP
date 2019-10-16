//Made by Max Bronnikov

// Task F about Gilberts hotel

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MODULO 1000000007

// buzy - number of elements in massive 
// elememt j in massive Groups - number of persons in group j-1 (0 group not in massive)

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
      --x; // we search number of room, rooms in [0, 1, ....], but x in [1, 2, ....]
      --g; // 0 group not in vector

      //if group not 0 and if has infinity persons: numbers of rooms in [1, 3, ..., 2t+1]
      if(g > 0 && !Groupes[g]){
        x<<=1;
        ++x;
      }

      // search number of room:
      for(int32_t j = g+1; j < buzy; ++j){
        // group j has k person: new x is x+k
        if(Groupes[j]){
          x+=Groupes[j];
        }else{ // else: new x is 2x
          x<<=1;
        }
        
        // mod of res
        if(x >= MODULO){
          x-= MODULO;
        }
      }
      
      // finally room
      printf("%"PRId32"\n", x);
      break;

    case 3:
      scanf("%"SCNd32, &x);

      // making reverse expresion of case 2:
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

      // finally group:
      printf("%"PRId32"\n", ++j);
      break;
    
    default:
      printf("Error\n");
      return 1;
    }
  }

  return 0;
}