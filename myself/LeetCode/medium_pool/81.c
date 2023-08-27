#include <stdio.h>
#include <stdbool.h>

bool binsearch(const int* nums, int l, int r, int target) 
{
    while(l < r) {
        const int m = (l + r) >> 1;
        const int elm = nums[m];

        if(target == elm) {
            return true;
        }

        if(target < elm) {
            r = m - 1;
            continue;
        }

        l = m + 1;
    }

    return nums[l] == target;
}


bool hard_search(const int* nums, int l, int r, int target) 
{
    if(l >= r) {
        return nums[l] == target;
    }

    const int m = (l + r) >> 1;
    const int elm = nums[m];

    if(elm == target) {
        return true;
    }

    const int ell = nums[l];
    const int elr = nums[r];

    if(ell < elm && target < elm && target >= ell) {
        return binsearch(nums, l, m - 1, target);
    }

    if(elm < elr && target > elm && target <= elr) {
        return binsearch(nums, m + 1, r, target);
    }

    if(ell >= elm && (target >= ell || target <= elm) && hard_search(nums, l, m - 1, target)) {
        return true;
    }

    if(elm >= elr && (target <= elr || target >= elm) && hard_search(nums, m + 1, r, target)) {
        return true;
    }

    return false;
}


bool search(const int* nums, int size, int target){
    int r = size - 1;

    if(nums[0] < nums[r]) {
        return binsearch(nums, 0, r, target);
    }

    return hard_search(nums, 0, r, target);
}

int main() 
{
    const int arr[] = {3, 5, 1};
    printf("%d\n", search(arr, sizeof(arr) / sizeof(int), 1));
    return 0;
}
