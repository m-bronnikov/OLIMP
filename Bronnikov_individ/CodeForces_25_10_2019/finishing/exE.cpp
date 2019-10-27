// Made by Bronnikov Max
#include <iostream>
#define MODULO 1000000007

using namespace std;


long long ext_gcd(long long a, long long b, long long& x, long long& y){
    if(!a){
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long g = ext_gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;
}

int main(){
    short N;
    cin >> N;
    for(short i = 0; i < N; ++i){
        long long a, b, c;
        long long x, y, cof;
        cin >> a >> b >> c;
        long long g = ext_gcd(a, b, x, y);
        if(c % g){
            cout << "-1" << endl;
            continue;
        }
        cof = c / g;
        x *= cof;
        y *= cof;
        cout << g << ' ' << x << ' ' << y << endl;
    }
    return 0;
}