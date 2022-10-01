#include <stdio.h>

int binsearch_upper_bound(const int* arr, int size, int elem)
{
    int l = 0;
    int r = size;

    while(l < r)
    {
        int m = (l + r) >> 1;

        if(arr[m] <= elem)
            l = m + 1;
        else
            r = m;
    }

    return l;
}


int searchInsert(const int* nums, int size, int target){
    int ans = binsearch_upper_bound(nums, size, target);

    if(nums[ans - 1] == target)
    {
        return ans - 1;
    }

    return ans;
}


int main()
{
    int nums[] = {0, 1, 2, 4};
    int target = 3;

    printf("%d\n", searchInsert(nums, sizeof(nums)/sizeof(int), target));

    return 0;
}