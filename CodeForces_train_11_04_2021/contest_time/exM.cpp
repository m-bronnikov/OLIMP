// Made by Max Bronnikov and Max Zhivykh
#include <iostream>
#include <vector>
 
using namespace std;
 
const long long MOD = 1e9 + 7;
 
//base ^ p
long long bin_pow(long long base, long long p) {
    if (p == 0) {
        return 1;
    }
    
    if (p == 1) {
        return base;
    }
 
    if (p % 2 == 0) {
        long long t = bin_pow(base, p / 2);
        return t * t % MOD;
    } else {
        return bin_pow(base, p - 1) * base % MOD;
    }
}
 
long long inverse_element(long long x) {
    return bin_pow(x, MOD - 2);
}
 
//(a / b) mod m
long long divide(long long a, long long b) {
    return a * inverse_element(b) % MOD;
}
 
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        long long i1, j1, i2, j2;
        cin >> i1 >> i2 >> j1 >> j2;
 
        long long ans = bin_pow(3, j1) * bin_pow(2, i1) % MOD;
 
        ans = ans * divide(bin_pow(3, j2 - j1 + 1) - 1, 2) % MOD;
        ans = ans * (bin_pow(2, i2 - i1 + 1) - 1) % MOD;
 
        cout << ans << endl;
    }
 
    return 0;
}