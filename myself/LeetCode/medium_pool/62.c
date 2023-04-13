#include <stdio.h>

#include <stdlib.h>

void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}


int uniquePaths(int m, int n)
{
    if(n > m) {
        swap(&n, &m);
    }

    // init memo
    int* memo = (int*) malloc(n * sizeof(int));
    for(int j = 0; j < n; ++j) { memo[j] = 1; }

    // start dp search
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            memo[j] += memo[j - 1];
        }
    }
    int score = memo[n - 1];
    
    free(memo);
    return score;
}


int main() {
    printf("%d\n", uniquePaths(3, 7));
    return 0;
}