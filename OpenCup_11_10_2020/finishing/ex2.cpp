
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int A, B, C, num;
    std::cin >> A >> B >> C;
    num = (C - 1) / 5  + 1;

    int numinator = 1, denuminator = 1;


    if (num > B){
        std::cout << 1 << std::endl;
        return 0;
    }

    while(num--){
        numinator *= B--;
        denuminator  *= A--;
    }

    std::cout << 1.0 - ((double) numinator) / ((double) denuminator) << std::endl;

    return 0;
}