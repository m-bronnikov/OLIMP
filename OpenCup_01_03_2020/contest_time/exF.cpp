// Made by Bronnikov Max and Lina Veltman
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    int N, K;
    cin >> N >> K;
    vector<vector<int>> field(N, vector<int>(N)), dp(N, vector<int>(N, -1));
    //read:
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> field[i][j];
            if(field[i][j] == 1){
                dp[i][j] = 0;
            }
        }
    }

    // main loop:
    for(int k = 1; k < K; ++k){
        bool flag = true;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(field[i][j] != k){
                    continue;
                }
                flag = false;
                for(int ii = 0; ii < N; ++ii){
                    for(int jj = 0; jj < N; ++jj){
                        if(field[ii][jj] == k + 1){
                            int r = dp[i][j] + abs(ii - i) + abs(jj - j);
                            if(dp[ii][jj] < 0){
                                dp[ii][jj] = r;
                                continue;
                            }
                            dp[ii][jj] = dp[ii][jj] > r ? r : dp[ii][jj];
                        }
                    }
                }
            }
        }
        if(flag){
            cout << -1 << endl;
            return 0;
        }
    }
    int min = 100000000;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(field[i][j] == K){
                min = min > dp[i][j] ? dp[i][j] : min;
            }
        }
    }
    cout << min << endl;
    return 0;   
}