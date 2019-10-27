#ifndef _EUCLID_ALGS_
#define _EUCLID_ALGS_
#include <inttypes.h>
#include <algorithm>

int64_t ext_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y);
int64_t gcd(int64_t a, int64_t b);

// extended Euclid algo gives x and y for xa + yb = gcd(a,b):

int64_t ext_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y){
    if(!a){
        x = 0;
        y = 1;
        return b;
    }
    int64_t x1, y1;
    int64_t g = ext_gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

// simple Euclid algo:
int64_t gcd(int64_t a, int64_t b){
    while(a){
        b %= a;
        std::swap(a, b);
    }
    return b;
}

#endif