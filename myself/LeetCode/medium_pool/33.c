#include <stdio.h>

int wild_binsearch(const int* arr, int size, int target)
{
    #define is_left(x) (x >= arr[0])

    int l = 0;
    int r = size - 1;

    const int target_is_left = is_left(target);

    while(l < r)
    {
        const int m = (l + r) >> 1;

        const int elem_is_left = is_left(arr[m]);

        if(elem_is_left && !target_is_left)
        {
            l = m + 1;
            continue;
        }
        if(!elem_is_left && target_is_left)
        {
            r = m - 1;
            continue;
        }

        if(arr[m] < target)
            l = m + 1;
        else
            r = m;
    }

    return l;
}


int search(const int* nums, int size, int target){
    const int ans = wild_binsearch(nums, size, target);
    return nums[ans] == target ? ans : -1;
}


int main()
{
    int nums[] = {1};
    int target = 2;

    printf("%d\n", search(nums, sizeof(nums)/sizeof(int), target));

    return 0;
}