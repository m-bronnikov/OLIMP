#include <stdio.h>

#define swap(type, lhs, rhs)    \
do{                             \
    type tmp = lhs;             \
    lhs = rhs;                  \
    rhs = tmp;                  \
}while(0)

int binsearch_upper_bound(int* arr, int size, int elem)
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

double findMedianSortedArrays(int* arr_1, int size_1, int* arr_2, int size_2){
    // let's add in larger array due to more complex bin search
    if(size_2 > size_1)
    {
        swap(int, size_1, size_2);
        swap(int*, arr_1, arr_2);
    }

    const int overall_len = size_1 + size_2;
    const int half_overall_len = (overall_len + 1) >> 1;
    int left_processed = 0;
    int right_processed = 0;

    // left and right middle element: `answer = (lm + rm) / 2.0`
    int lm_val;
    int rm_val;

    while(size_2 > 0)
    {
        // get middle element in second array
        int m2_idx = size_2 >> 1;
        int m2_elem = arr_2[m2_idx];
        
        int m1_idx = binsearch_upper_bound(arr_1, size_1, m2_elem);

        // check left proceed
        int possible_left_proceed = left_processed + m1_idx + (m2_idx + 1);
        if(possible_left_proceed <= half_overall_len)
        {
            if(possible_left_proceed == half_overall_len)
            {
                lm_val = m2_elem;
            }

            left_processed = possible_left_proceed;

            arr_1 += m1_idx;
            size_1 -= m1_idx;

            arr_2 += (m2_idx + 1);
            size_2 -= (m2_idx + 1);

            continue;
        }

        // check right proceed
        int possible_right_proceed = right_processed + (size_1 - m1_idx) + (size_2 - m2_idx);
        if(possible_right_proceed <= half_overall_len)
        {
            if(possible_right_proceed == half_overall_len)
            {
                rm_val = m2_elem;
            }

            right_processed = possible_right_proceed;

            size_1 -= (size_1 - m1_idx);

            size_2 -= (size_2 - m2_idx);


            continue;
        }
    }

    if(left_processed < half_overall_len && half_overall_len <= left_processed + size_1)
    {
        lm_val = arr_1[half_overall_len - left_processed - 1];
    }

    if(right_processed < half_overall_len && half_overall_len <= right_processed + size_1)
    {
        rm_val = arr_1[size_1 - (half_overall_len - right_processed)];
    }

    return (overall_len & 1) ? lm_val : (lm_val + rm_val) / 2.0;
}


#define lenof(arr) sizeof(arr) / sizeof((arr)[0])

int main()
{
    int arr_1[] = {1, 2, 4, 4, 7, 8};
    int arr_2[] = {0, 2, 3, 5, 5, 9};


    printf("%f\n", findMedianSortedArrays(arr_1, lenof(arr_1), arr_2, lenof(arr_2)));

    return 0;
}
