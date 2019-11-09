// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<long long> vc(N, 0);
    vector<long long> mp(N + 1, 0);

    /*for(int i = 0; i < N; ++i){
        cin >> vc[i];
    } */
    for(int i = 0; i < Q; ++i){
        int l, r, v;
        cin >> l >> r >> v;
        mp[l - 1] += v;
        mp[r] -= v;
    }
    long long now = 0;
    --N;
    for(int i = 0; i < N; ++i){
        now += mp[i];
        vc[i] += now;
        cout << vc[i] << ' ';
    }
    now += mp[N];
    vc[N] += now;
    cout << vc[N] << endl;
    return 0;
}