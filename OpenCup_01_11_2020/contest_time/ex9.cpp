// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

long long int bin_pow(long long a, long long n){
    long long res = 1;
    while(n){
        if(n & 1){
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}


int main(){
    int T;
    cin >> T;
    while (T--){
        long long W, D;
        double maxp = 0.0;
        cin >> W >> D;
        while(W--){
            long long N, F, M;
            cin >> N >> M >> F;

            long long maxlim = M*N;

            if(D - F < 2){
                maxp = 1.0;
                continue;
            }

            if(D - F > maxlim){
                continue;
            }

            vector<vector<long long>> dp(N + 1, vector<long long>(maxlim + 1, 0));
            for(int j = 1; j <= M; ++j){
                dp[1][j] = 1;
            }

            for(long long i = 2; i <= N; ++i){
                long long lim = M*i;
                for(long long j = i; j <= lim; ++j){
                    for(long long k = j > M ? M : j; k >= 1; --k){
                        if(j > k){
                            dp[i][j] += dp[i - 1][j - k];
                        }
                    }
                }
            }

            long long vars = 0;
            for(int j = D - F; j <= maxlim; ++j){
                vars += dp[N][j];
            }

            double prob = (double) vars / ((double) bin_pow(M, N));
            maxp = prob > maxp ? prob : maxp;
        }

        cout << setprecision(11) << maxp << endl;
    }

    return 0;   
}