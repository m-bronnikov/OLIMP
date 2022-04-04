#include <stdio.h>


int numberOfSteps(int num){
    int steps = 0;

    do
    {
        steps += (num & 1);
    } while ((num >>= 1) && ++steps);
    
    return steps;
}


int main()
{
    int num;

    scanf("%d", &num);
    printf("steps: %d\n", numberOfSteps(num));

    return 0;
}