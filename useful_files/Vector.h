#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTVALUE 2 // all allocs multyplyes size on 2


typedef unsigned long long int TypeV;

typedef struct Item{
  TypeV value;
  int key;
} Item;

typedef struct vector{
  unsigned int len;
  unsigned int buzy;
  Item* data;
} Vector;

void Count_Sort(Vector* A);
void Create_Vector(Vector* A);
void Delete_Vector(Vector* A);
void Insert_Vector(Vector* A, Item* item);
void Read_Item(Vector* A);
void Vector_Print(Vector* A);

// init vector:
void Create_Vector(Vector* A){
  A->len = STARTVALUE;
  A->buzy = 0;
  A->data = (Item*) malloc(STARTVALUE * sizeof(Item));
  if(!A->data){
    fprintf(stderr, "Allocate Vector Memory Error!\n");
    exit(EXIT_SUCCESS);
  }
}

// destroy vector:
void Delete_Vector(Vector* A){
  free(A->data);
  A->data = NULL;
}

// realloc vector
void Resize_Vector(Vector* A){
  A->len *= STARTVALUE;
  A->data = (Item*) realloc(A->data, A->len * sizeof(Item));
  if(!A->data){
    fprintf(stderr, "Reallocate Vector Memory Error!\n");
    exit(EXIT_SUCCESS);
  }
}

// insert value in vector
void Insert_Vector(Vector* A, Item* item){
  if(A->len == A->buzy){
    Resize_Vector(A);
  }
  A->data[A->buzy].key = item->key;
  A->data[A->buzy++].value = item->value;
}

// read vlalues and insert in vector
void Read_Item(Vector* A){
  char buf[6];
  Item item;
  while(scanf("%s\t%llu", buf, &item.value) != EOF){
    item.key = (int) atoi(buf);
    Insert_Vector(A, &item);
  }
}

// printing vector
void Vector_Print(Vector* A){
  for(unsigned i = 0; i < A->buzy; i++){
    for(unsigned j = 100000; j != 1; j/=10){
      if(!(A->data[i].key / j)){
        printf("0");
      }else{
        break;
      }
    }
    printf("%d\t%llu\n", A->data[i].key, A->data[i].value);
  }
}

#endif