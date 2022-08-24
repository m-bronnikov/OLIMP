#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == val)
        {
            nums[i--] = nums[--numsSize];
        }
    }
    
    return numsSize;
}

int main()
{
    int a[] = {3, 4, 1, 5, 6, 2, 1};
    int size = removeElement(a, 7, 1);
    for(int i = 0; i < size; ++i){
        printf("%d\n", a[i]);
    }

    return 0;
}