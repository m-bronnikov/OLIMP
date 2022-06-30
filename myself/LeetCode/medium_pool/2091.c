#include <stdio.h>


#define swap(type, lhs, rhs)    \
do{                             \
    type tmp = lhs;             \
    lhs = rhs;                  \
    rhs = tmp;                  \
}while(0)



int minimumDeletions(int* nums, int size){
    int min_idx = 0;
    int max_idx = 0;

    for(int i = 1; i < size; ++i)
    {
        min_idx = nums[min_idx] > nums[i] ? i : min_idx;
        max_idx = nums[max_idx] > nums[i] ? max_idx : i; // specially update idx for equal values
    }

    if(min_idx > max_idx)
    {
        swap(int, min_idx, max_idx);
    }

    int shortest_is_left = (min_idx + 1 < size - max_idx) ? 1 : 0;
    int result = shortest_is_left ? min_idx + 1 : size - max_idx;

    if(nums[min_idx] == nums[max_idx])
    {
        return result;
    }

    int first_count = max_idx - min_idx;
    int second_count = shortest_is_left ? size - max_idx : min_idx + 1;

    return result + (first_count < second_count ? first_count : second_count);
}

int main(){
    int nums[1] = {101};
    printf("%d\n", minimumDeletions(nums, 1));
    return 0;
}
