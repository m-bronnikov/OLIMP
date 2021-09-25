// Made by Bronnikov Max
#include <iostream>

int main(){
    unsigned long long res = 1;
    int n, N;
    unsigned long long a;
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> a >> n;
        res = 1;
        while(n){
            if(n&1){
                res = (res * a) % 1000000007;
            }
            a*=a;
            a%=1000000007;
            n>>=1;
        }
        std::cout << res << std::endl;
    }
}