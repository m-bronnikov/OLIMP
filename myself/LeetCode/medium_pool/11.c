#include <stdio.h>


int maxArea(const int* height, int size){
    const int* start = height;
    const int* end = height + size - 1;

    int max_square = 0;
    while(start < end)
    {
        int height = *start;
        int go_left = 1;

        if(*end < *start)
        {
            height = *end;
            go_left = 0;
        }

        int square = height * (end - start);
        max_square = square > max_square ? square : max_square;

        go_left ? ++start : --end;
    }

    return max_square;
}


int main()
{
    int space[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(space, 9));
    return 0;
}