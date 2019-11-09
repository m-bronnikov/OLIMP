// Made by Max Bronnikov
 
#include <iostream>
 
using namespace std;

#define MODULO 1000000007

 
int main(){
    int N;
    int n2 = 1;
    long long a = 0;
 
    cin >> N;
 
    long long res = 0;

    for (int i = 1; i < N; ++i){
        n2 <<= 1;
        if(n2 >= MODULO){
            n2-=MODULO;
        }
    }
 
    for(int i = 0; i < N; ++i){
        cin >> a;
        res += a;
    }

    res *= n2;
    res %= MODULO;

    cout << res << endl;
    return 0;
}