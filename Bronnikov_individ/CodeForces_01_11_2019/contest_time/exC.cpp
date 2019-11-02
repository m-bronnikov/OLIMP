// Made by Max Bronnikov
#include <iostream>
#include <vector>

#define MODULO 1000000007

using namespace std;

int main(){
    short n, k, m;

    cin >> n >> k >> m;

    vector<int> path(n + 1, 0);
    vector<int> dang(n + 1, 1);

    for(short i = 0; i < m; ++i){
        short a;
        cin >> a;
        dang[a] = 0;
    }

    if(n < 2){
        cout << '1' << endl;
    }

    path[0] = 1;
    path[1] = 1;

    k  = k < n ? k : n;

    for(short i = 2; i <= k; ++i){
        for(short j = 0; j < i; ++j){
            path[i] += path[j] * dang[j];
            if(path[i] >= MODULO){
                path[i] -= MODULO;
            }
        }
        // cout << i << ' ' << path[i] << endl;
    }

    for(short i = k + 1; i <=n; ++i){
        for(short j = i - k; j < i; ++j){
            path[i] += path[j] * dang[j];
            if(path[i] >= MODULO){
                path[i] -= MODULO;
            }
        }
        // cout<< i << ' ' <<  path[i] << endl;
    }

    cout << path[n] << endl;

    return 0;
}