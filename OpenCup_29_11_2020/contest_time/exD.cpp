// Made by Max Bronnikov
#include <vector>
#include <iostream>

using namespace std;

#define MODULO 1000000007

// pow by modulo:
long long int bin_pow_mod(long long a, long long n, long long mod){
    long long res = 1;
    while(n){
        if(n & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return res;
}


int main(){
    int n, x;
    while(cin >> n >> x){
        vector<long long> a(n);
        vector<long long> b(n);

        for(auto& el : a){
            cin >> el;
        }

        for(auto& el : b){
            cin >> el;
        }

        long long determine = x;

        for(int i = 0; i < n; ++i){
            determine += a[i]*b[i];
            determine %= MODULO;
        }

        determine *= bin_pow_mod(x, n - 1, MODULO);

        determine %= MODULO;

        cout << determine << endl;
    }

    return 0;
}