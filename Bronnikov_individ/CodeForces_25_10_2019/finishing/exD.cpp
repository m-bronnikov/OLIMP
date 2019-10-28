// Made by Bronnikov Max
#include <inttypes.h>
#include <algorithm>
#include <iostream>

int64_t gcd(int64_t a, int64_t b){
    while(a){
        b %= a;
        std::swap(a, b);
    }
    return b;
}

int main(){
    short N;
    long long a, b = 1;
    std::cin >> N;
    for(short i = 0; i < N; ++i){
        std::cin >> a;
        b = b / gcd(a, b); 
        b *= a;
    }
    std::cout << b << std::endl;
    return 0;
}