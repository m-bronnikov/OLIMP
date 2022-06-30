#include <stdio.h>

int maxScore(int* points, int points_size, int k){
    // inclusive scan
    for(int i = 1; i < points_size; ++i)
    {
        points[i] += points[i - 1];
    }

    int overall_sum = points[points_size - 1];

    if(k >= points_size)
    {
        return overall_sum;
    }

    int max_points = overall_sum - points[points_size - k - 1];
    for(int i = 0; i < k; ++i)
    {
        int possible_points = points[i] + overall_sum - points[points_size - k + i];
        max_points = max_points > possible_points ? max_points : possible_points;
    }

    return max_points;
}

int main(){
    int a[7] = {100, 40, 17, 9, 73, 75};
    printf("%d\n", maxScore(a, 6, 3));
    return 0;
}
