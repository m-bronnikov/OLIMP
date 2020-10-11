#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    long long N;
    cin >> N;

    long long M = (N * (N - 1)) >> 1;

    vector<long long> wires(M);

    for(auto& w : wires){
        cin >> w;
    }

    sort(begin(wires), end(wires));

    long long ans1 = 0, ans2 = 0;


    for(long long i = 0, step = N - 1, j = M - step; i < N - 1; ++i, --step, j -= step){
        ans1 += wires[i];
        ans2 += wires[j];
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}