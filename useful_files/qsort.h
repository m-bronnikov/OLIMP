#include <stdio.h>
#include <stdlib.h>
 
//first arg: pointer to massive, second arg: len of massive
void qsortRecursive(unsigned *mas, unsigned size) {
    //Указатели в начало и в конец массива
    unsigned i = 0;
    unsigned j = size;
 
    //Центральный элемент массива
    unsigned mid = mas[j >> 1];
    --j;
    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            ++i;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            --j;
        }
 
        //Меняем элементы местами
        if (i < j) {
            unsigned tmp = mas[i];
            mas[i++] = mas[j];
            mas[j--] = tmp;
        }else if(i == j){
            ++i;
            if(j){
                --j;
            }
        }
    } while (i <= j);
 
    //Рекурсивные вызовы, если осталось, что сортировать
    if(j++) {
        //"Левый кусок"
        qsortRecursive(mas, j);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(mas + i, size - i);
    }
}
