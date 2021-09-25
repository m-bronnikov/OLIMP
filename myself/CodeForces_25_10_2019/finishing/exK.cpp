// Made by Max Bronnikov
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N;
    std::cin >> N;
    std::vector<int> A;
    std::vector<int> P;
    A.reserve(N);
    P.reserve(N);
    for(int i = 0; i < N; ++i){
        int a;
        std::cin >> a;
        A.push_back(a);
    }

    long long p_sum = 0;

    for(int i = 0; i < N; ++i){
        int p;
        std::cin >> p;
        p_sum += p;
        P.push_back(p);
    }

    std::sort(A.begin(), A.end());
    std::sort(P.begin(), P.end());

    double res = 0.0;
    for(int i = 0; i < N; ++i){
        res += (double)A[i] * ((double)P[i] / (double)p_sum);
    }

    printf("%.12e\n", res);
    return 0;
}