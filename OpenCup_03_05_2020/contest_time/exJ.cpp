#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        long long unsigned int K;
        cin >> K;
        --K;
        long long unsigned mask = 1;
        long long unsigned ans = 1;
        for(int j = 0; j < 64; ++j){
            if(mask & K){
                ans <<= 1;
            }
            mask <<= 1;
        }
        cout << ans << endl;
    }
    return 0;
}