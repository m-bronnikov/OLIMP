#include <iostream>

using namespace std;


int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t){
        long long N, S, K;
        int sum_1 = 0;
        int sum_0 = 0;
        cin >> N >> S >> K;
        for(long long i = 0; i < K; ++i){
            long long num;
            cin >> num;
            if(num & 1){
                sum_1 ^= 1;
            }else{
                sum_0 ^= 1;
            }
        }
        //cout << sum_0 << ' ' << sum_1 << endl;
        if(S & 1){
            if(N == 1){
                cout << sum_1 << endl;
            }else{
                if(N&1){
                    cout << sum_1 + sum_1 * sum_0 << endl;
                }else{
                    cout << 0 << endl;
                }
            }
        }else{
            if(N == 1){
                cout << sum_0 << endl;
            }else{
                if(N&1){
                cout << sum_0 + sum_1 * sum_0 << endl;
                }else{
                    cout << sum_0 + sum_1 << endl;
                }
            }
        }
    }
    return 0;
}
