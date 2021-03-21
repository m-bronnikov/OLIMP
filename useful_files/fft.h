#ifndef __FAST_FURIER_TRANSFORM_H__
#define __FAST_FURIER_TRANSFORM_H__

#include <vector>
#include <complex>
#include <math.h>

using namespace std;

// modulo:S
#define MODULO 998244353
// 2 << 18
#define UPPER_BOUND 262144 
// such number n that `powmod(n, UPPER_BOUND, MODULO) == 1` for MODULO (define itself for your modulo)
#define ROOT 2192
// inverted primary root:
#define INV_ROOT 79695603

// const int mod = 7340033;
// const int root = 5;
// const int root_1 = 4404020;
// const int root_pw = 1 << 20;

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

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

void fft(vector<int>& a, bool invert) {
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


void fft(vector<complex<double>>& a, bool invert) {
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
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        complex<double> wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; j++) {
                complex<double> u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (complex<double> & x : a)
            x /= n;
    }
}

// Multiplication of real polinomos:
void multiply(vector<double>& result, const vector<double>& a, const vector<double>& b) {
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    result.resize(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i].real();
}

// Multiplication of integer polinomos by MODULO:
void multiply(vector<int>& result, const vector<int>& a, const vector<int>& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    result.resize(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i];
}

#endif