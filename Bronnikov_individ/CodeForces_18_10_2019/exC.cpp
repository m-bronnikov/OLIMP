#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

#define MODULO 1000000007


// count sort
unsigned* Count_Sort(unsigned* A, unsigned N, unsigned SUPR){
    unsigned j = 0/*, C[SUPR]*/;
    unsigned* C = (unsigned*)malloc(sizeof(unsigned) * SUPR);
    memset(C, 0, SUPR*sizeof(unsigned));

    for(j = 0; j < N; ++j){
      ++C[A[j]];
    }
    for(j = 1; j < SUPR; ++j){
      C[j]+=C[j-1];
    }
    unsigned* B = (unsigned*) malloc(sizeof(unsigned) * N);
    
    for(j=N-1; j>0; j--){
      --C[A[j]];
      B[C[A[j]]] = A[j];
    //memcpy(&B[--C[A->data[j].key]], &A->data[j], sizeof(Item));
    }
    --C[A[0]];
    B[C[A[0]]] = A[0];

    free(A);
    free(C);
    return B;
}



int main(){
    int m, k, mod;
    long long unsigned a, aa;
    int n;
    cin >> n;
    cin >> a >> m >> k >> mod;
    aa = a;
    //cout << n << ' ' << a << ' ' << m << ' ' << k << mod << endl;
    unsigned* C = (unsigned*)malloc(sizeof(unsigned) * mod);
    memset(C, 0, mod*sizeof(unsigned));

    for(int i = 0; i < n; ++i){
        ++C[a];
        a = (a * m + k) % mod;
    } 

    int j = 0/*, C[SUPR]*/;

    for(j = 1; j < mod; ++j){
      C[j]+=C[j-1];
    }
    a = 0;
    unsigned i = 0;
    for(j=0; j < n; ++j){
      --C[aa];
      i = C[aa];
      a += (long long unsigned)(i + 1) * aa;
      if(a >= MODULO){
          a%=MODULO;
      }
      aa = (aa * m + k) % mod;
    //memcpy(&B[--C[A->data[j].key]], &A->data[j], sizeof(Item));
    }
    free(C);
    /*
    a = 0;
    for(int i = 0; i < n; ++i){
        a+= (long long unsigned)(i+1) * v[i];
        a%=MODULO;
    }*/
    cout << a << std::endl;
    return 0;
}