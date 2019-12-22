// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long N, M;
    cin >> N >> M;
    long long ans = 0;

    long long r1 = 0;
    for(long long i = 2; i <= N; ++i){
        r1 += i >> 1;
    }
    ans += r1*(M+1);

    //cout << "g:" << ans;

    r1 = 0;
    for(long long i = 2; i <= M; ++i){
        r1 += i >> 1;
    }
    ans += r1*(N+1);

    for(long long i = 1; i < N; ++i){
        for(long long j = 1; j < M; ++j){
            long long x = min(M - j, j);
            long long y = min(N - i, i);
            //cout << "x:" << x  << " y:" << y << endl;
            ans += x * y << 1;
        }
    }

    cout << ans << endl;
    return 0;
}