// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

long long dp(long long l, long long r, vector<vector<long long>>& memo, vector<long long>& cols, vector<long long>& rows){
    if(memo[l][r] != -1){
        return memo[l][r];
    }
    if(l == r){
        memo[l][r] = 0;
        return 0;
    }
    long long result = dp(l+1, r, memo, cols, rows) + rows[l] * cols[r] * cols[l];
    for(long long k = l + 1; k < r; ++k){
        result = min(result, dp(l, k, memo, cols, rows) + dp(k + 1, r, memo, cols, rows) + rows[l] * cols[r] * cols[k]);
    }
    memo[l][r] = result;
    return result;
}

int main(){
    int N;
    cin >> N;
    vector<vector<long long>> memo(N, vector<long long>(N, -1));
    vector<long long> cols(N, 0);
    vector<long long> rows(N, 0);
    for(int i = 0; i < N; ++i){
        long long c, r;
        cin >> r >> c;
        cols[i] = c;
        rows[i] = r;
    }
    cout << dp(0, N - 1, memo, cols, rows) << endl;
    return 0;
}