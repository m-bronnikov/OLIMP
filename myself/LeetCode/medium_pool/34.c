#include <stdio.h>

#include <stdlib.h>

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

int binsearch_lower_bound(const int* arr, int size, int elem)
{
    int l = 0;
    int r = size - 1;

    while(l < r)
    {
        int m = (l + r) >> 1;

        if(arr[m] < elem)
            l = m + 1;
        else
            r = m;
    }

    return l;
}


int* searchRange(const int* nums, int size, int target, int* return_size){
    int* ans = (int*) malloc(2 * sizeof(int));
    *return_size = 2;

    ans[0] = binsearch_lower_bound(nums, size, target);
    ans[1] = binsearch_upper_bound(&nums[ans[0]], size - ans[0], target) - 1 + ans[0];

    if(size == 0 || nums[ans[0]] != target)
    {
        ans[0] = ans[1] = -1;
    }

    return ans;
}


int main()
{
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 6;
    int size;
    
    int* ans = searchRange(nums, sizeof(nums)/sizeof(int), target, &size);

    printf("%d : %d\n", ans[0], ans[1]);
    free(ans);

    return 0;
}