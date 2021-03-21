// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <complex>

using namespace std;

#define MODULO 998244353
#define UPPER_BOUND 262144
#define ROOT 2192
#define INV_ROOT 79695603
// #define DIV 3808
// #define POW 18

// const int mod = 7340033;
// const int root = 5;
// const int root_1 = 4404020;
// const int root_pw = 1 << 20;

int extended_euclidean(int a, int b, int& x, int& y){
    if(!a){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int g = extended_euclidean(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

int inverse(int a, int m){
    int x, y;
    int g = extended_euclidean(a, m, x, y);

    
    x = (x % m + m) % m;
    return x;
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? INV_ROOT : ROOT;
        for (int i = len; i < UPPER_BOUND; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % MODULO);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % MODULO);
                a[i+j] = u + v < MODULO ? u + v : u + v - MODULO;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MODULO;
                w = (int)(1LL * w * wlen % MODULO);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, MODULO);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % MODULO);
    }
}


// vector<int> summation(vector<int> const& a, vector<int> const& b) {
//     vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
//     int n = 1;
//     while (n < a.size() + b.size()) 
//         n <<= 1;
//     fa.resize(n);
//     fb.resize(n);

//     fft(fa, false);
//     fft(fb, false);
//     for (int i = 0; i < n; i++)
//         fa[i] += fb[i];
//     fft(fa, true);

//     vector<int> result(n);
//     for (int i = 0; i < n; i++)
//         result[i] = round(fa[i].real());
//     return result;
// }

int main(){
    vector<int> a = {1, 2, 3, 9};

    return 0;
}