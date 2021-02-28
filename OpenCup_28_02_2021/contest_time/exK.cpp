// Made by Max Bronnikov
#include <iostream>

using namespace std;

#define MODULO 998244353

int main(){
    string number;

    cin >> number;

    long long ans = 0;

    for(auto c : number){
        ans *= 10;
        ans += static_cast<long long>(c - '0');

        if(ans >= MODULO){
            ans %= MODULO;
        }
    }

    cout << ans << endl;

    return 0;
}