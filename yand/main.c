#include <stdio.h>
#include <stdlib.h>
 
 
void quicksort(unsigned *mas, unsigned first, unsigned last)
{
unsigned mid, count;
unsigned f=first, l=last;
mid=mas[(f+l) >> 1]; //вычисление опорного элемента
while(f < l)
{
while (mas[f]<mid) ++f;
while (mas[l]>mid) --l;
if (f<=l) //перестановка элементов
{
count=mas[f];
mas[f]=mas[l];
mas[l]=count;
++f;
--l;
}
}
if (first<l) quicksort(mas, first, l);
if (f<last) quicksort(mas, f, last);
}
 
 
 
int main(){
    unsigned* data;
    unsigned buzy;
    scanf("%u", &buzy);
    
    data = (unsigned*) malloc(buzy * sizeof(unsigned));
    for(unsigned i = 0; i < buzy; ++i){
        scanf("%u", &data[i]);
        //printf("%u ", data[i]);
    }
    quicksort(data, 0, buzy-1);
    for(unsigned i = 0; i < buzy; ++i){
        printf("%u ", data[i]);
    }
    free(data);
    return 0;
}