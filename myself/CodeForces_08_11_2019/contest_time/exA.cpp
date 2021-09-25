// Made by Bronnikov Max
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, Q;
    cin >> N;
    int a;
    //vector<int> a(N);
    vector<long long> sums(N + 1, 0);
    for(int i = 0; i < N; ++i){
        cin >> a;
        sums[i + 1] = sums[i] + a;
    }
    cin >> Q;
    for(int i = 0; i < Q; ++i){
        int l, r;
        cin >> l >> r;
        cout << sums[r] - sums[l - 1] << endl;;
    }
    return 0;
}