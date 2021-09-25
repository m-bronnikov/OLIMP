// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

#define MODULO 1000000007


int main(){
    unsigned r, l;
    unsigned res = 0;
    cin >> l >> r;
    vector<unsigned> path(r + 1, 1);
    if(r == 1){
        cout << 1 << endl;
    }
    for(unsigned i = 2; i <= r; ++i){
        for(unsigned j = 2; j * i <= r; ++j){
            path[i * j] += path[i];
        }
        // cout << i << ' ' << path[i] << endl;
    }
    for(unsigned i = l; i <= r; ++i){
        res += path[i];
        if(res >= MODULO){
            res -= MODULO;
        }
    }
    cout << res << endl;
}