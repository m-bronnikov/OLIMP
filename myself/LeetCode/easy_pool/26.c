#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int j = 1;

    for(int i = 1; i < numsSize; ++i)
    {
        if(nums[i] == nums[j]) continue;
        nums[++j] = nums[i];
    }

    return j + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 4, 5, 5};
    int k = removeDuplicates(arr, sizeof(arr) / sizeof(int));

    printf("k = %d\n", k);
    for(int i = 0; i < k; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}