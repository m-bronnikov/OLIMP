#ifndef _COUNT_SORT_
#define _COUNT_SORT_

#include <ctype.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

#define SUPR 1000000 // Max number

unsigned* Count_Sort(unsigned* A, unsigned buzy);


// count sort
unsigned* Count_Sort(unsigned* A, unsigned buzy){
  if(!buzy){
    return A;
  }
  unsigned j = 0;
  unsigned* C = (unsigned*)malloc(sizeof(unsigned) * SUPR);
  memset(C, 0, SUPR*sizeof(unsigned));
  for(j = 0; j < buzy; j++){
    ++C[A[j]];
  }
  for(j = 1; j < SUPR; ++j){
    C[j]+=C[j-1];
  }
  unsigned* B = (unsigned*) malloc(sizeof(unsigned) * buzy);
  for(j=buzy-1; j>0; --j){
    --C[A[j]];
    B[C[A[j]]] = A[j]; // in ~half of itterations
  }
  --C[A[0]];
  B[C[A[0]]] = A[0];
  free(A);
  free(C);
  return B;
}

#endif