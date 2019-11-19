// Made by Max Bronnikov
#include <iostream>
#include <vector>

#define MODULO 1000000007

using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    //vector<int> path(n + k, 0);

    if(n < 2){
        cout << '1' << endl;
    }

    int ans = 1;
    int res = 1, lim = n - k;
    if(lim < 0){
        lim = 0;
    }
    for(int i = 1; i < lim; ++i){
        res <<= 1;
        if(res >= MODULO){
            res -= MODULO;
        }
        cout << res << endl;
    }
    for(int i = lim; i < n - 1; ++i){
        res <<= 1;
        if(res >= MODULO){
            res -= MODULO;
        }
        ans += res;
        if(ans >= MODULO){
            ans -= MODULO;
        }
        cout << res << endl;
    }
    cout << ans << endl;
    //path[0] = 1;

    //k  = k < n ? k : n;

    /*for(int i = 2; i <= k; ++i){
        for(int j = 0; j < i; ++j){
            path[i] += path[j];
            if(path[i] >= MODULO){
                path[i] -= MODULO;
            }
        }
        // cout << i << ' ' << path[i] << endl;
    }

    for(int i = k + 1; i <=n; ++i){
        for(int j = i - k; j < i; ++j){
            path[i] += path[j];
            if(path[i] >= MODULO){
                path[i] -= MODULO;
            }
        }
        // cout<< i << ' ' <<  path[i] << endl;
    }*/
/*
    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= k; ++j){
            path[i+j] += path[i];
            if(path[i+j] >= MODULO){
                path[i+j] -= MODULO;
            }
        }
    }

    cout << path[n] << endl;
*/
    return 0;
}