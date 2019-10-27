#ifndef _BIN_POWS_
#define _BIN_POWS_

long long int bin_pow(long long a, long long n);
long long int bin_pow_mod(long long a, long long n, long long mod);

// simple binpow:
long long int bin_pow(long long a, long long n){
    long long res = 1;
    while(n){
        if(n & 1){
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

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



#endif // _BIN_POWS_
