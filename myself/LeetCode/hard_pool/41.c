#include <stdio.h>

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int firstMissingPositive(int* nums, int size){
    for(int i = 0; i < size; ++i)
    {
        while(nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1])
        {
            swap(&nums[i], &nums[nums[i] - 1]);
        }
    }

    for(int i = 1; i <= size; ++i)
    {
        if(nums[i - 1] != i)
        {
            return i;
        }
    }

    return size + 1;
}

int main()
{
    int arr[] = {3, 4, -1, 1};
    printf("%d\n", firstMissingPositive(arr, 4));

    return 0;
}