#include <stdio.h>

void reverse(int* nums, int size)
{
    int half_size = size >> 1;
    for(int i = 0; i < half_size; ++i)
    {
        int num_to_swap = nums[i];
        nums[i] = nums[size - i - 1];
        nums[size - i - 1] = num_to_swap;
    }
}

void nextPermutation(int* nums, int size){
    // find non-sored position if exist
    int idx = size - 1;
    while(--idx >= 0)
    {
        int l = nums[idx];
        int r = nums[idx + 1];

        if(l < r) break;
    }

    // if array is sorted => just reverse
    if(idx < 0)
    {
        reverse(nums, size);
        return;
    }

    // value to swap
    int num_to_swap = nums[idx];

    // find position to swap
    int pos = idx;
    while(++pos < size)
    {
        if(nums[pos] <= num_to_swap)
            break;
    }
    
    // swap
    nums[idx] = nums[--pos];
    nums[pos] = num_to_swap;

    // sort from next after idx position using simple reverse
    ++idx;
    reverse(nums + idx, size - idx);
}

int main()
{
    int arr[] = {4, 1, 5, 2, 1, 5};
    nextPermutation(arr, 6);
    
    for(int i = 0; i < 6; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}