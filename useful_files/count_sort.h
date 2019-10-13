
#include <string.h>
#include "Vector.h"

#define SUPR 1000000 // Max number


// count sort
void Count_Sort(Vector* A){
  if(A->buzy){
    unsigned j = 0/*, C[SUPR]*/;
    unsigned* C = (unsigned*)malloc(sizeof(unsigned) * SUPR);
    if(!C){
      fprintf(stderr, "Allocate Second Vector Memory Error!\n");
      exit(EXIT_SUCCESS);
    }
    memset(C, 0, SUPR*sizeof(unsigned));
  // for(j = 0; j < SUPR; j++){
  //   C[j]=0;
  // }
    for(j = 0; j < A->buzy; j++){
      ++C[A->data[j].key];
    }
    for(j = 1; j < SUPR; j++){
      C[j]+=C[j-1];
    }
    Item* B = (Item*) malloc(sizeof(Item) * A->buzy);
    if(!B){
      fprintf(stderr, "Allocate Second Vector Memory Error!\n");
      exit(EXIT_SUCCESS);
    }
    for(j=A->buzy-1; j>0; j--){
      --C[A->data[j].key];
      B[C[A->data[j].key]].value = A->data[j].value; //Use of uninitialised value of size 8
      B[C[A->data[j].key]].key = A->data[j].key; // in ~half of itterations
    //memcpy(&B[--C[A->data[j].key]], &A->data[j], sizeof(Item));
    }
    --C[A->data[0].key];
    B[C[A->data[0].key]].value = A->data[0].value; //Use of uninitialised value of size 8
    B[C[A->data[0].key]].key = A->data[0].key;
    free(A->data);
    free(C);
    A->data = B;
  }
}




