// Made by Bronnikov Max
#include <iostream>
#include <vector>

int main(){
    unsigned long long res = 0;
    unsigned n, m;
    unsigned N = 1;
    std::cin >> n >> m;
    std::vector<bool> result(15485864, 0); 
    result[0] = result[1] = 1;
    unsigned long long i = 2;
    for(i = 2; N < n; ++i){
        if(result[i] != 0){
            continue;
        }
        ++N;
        for(unsigned long long j = i*i; j <= 15485863; j+=i){
            result[j] = 1;  
        }
    }
    
    for(; N <= m; ++i){
        if(result[i] != 0){
            continue;
        }
        ++N;
        res+=i;
        for(unsigned long long j = i*i; j <= 15485863; j+=i){
            result[j] = 1;
        }
    }
    std::cout << res << std::endl;
}