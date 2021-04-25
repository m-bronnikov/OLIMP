#ifndef _COUNT_SORT_
#define _COUNT_SORT_

#include <ctype.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

#define SUPR 1000000 // Max number

unsigned* Count_Sort(unsigned* A, unsigned size);


// count sort
unsigned* Count_Sort(unsigned* A, unsigned size){
  if(!size){
    return A;
  }

  unsigned* B = (unsigned*) malloc(sizeof(unsigned) * size);
  unsigned* C = (unsigned*)malloc(sizeof(unsigned) * SUPR);
  memset(C, 0, SUPR*sizeof(unsigned));

  // hystogram
  for(unsigned j = 0; j < size; j++){
    ++C[A[j]];
  }

  // inclusive scan
  for(unsigned j = 1; j < SUPR; ++j){
    C[j]+=C[j-1];
  }

  // sorting
  for(int j= size - 1; j >= 0; --j){
    --C[A[j]];
    B[C[A[j]]] = A[j];
  }

  free(A);
  free(C);
  return B;
}

#endif