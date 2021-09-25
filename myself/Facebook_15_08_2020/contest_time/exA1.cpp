#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MODULO 1000000007

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        int N, K, W;
        long long A, B, C, D;

        cin >> N >> K >> W;
        
        vector<long long> L(N);
        vector<long long> H(N);

        for(int i = 0; i < K; ++i){
            cin >> L[i];
        }

        cin >> A >> B >> C >> D;

        for(int i = K; i < N; ++i){
            L[i] = (A*L[i-2] + B*L[i-1] + C);

            if(L[i] >= D){
                L[i] %= D;
            }

            ++L[i];
        }

        for(int i = 0; i < K; ++i){
            cin >> H[i];
        }

        cin >> A >> B >> C >> D;

        for(int i = K; i < N; ++i){
            H[i] = (A*H[i-2] + B*H[i-1] + C);

            if(H[i] >= D){
                H[i] %= D;
            }

            ++H[i];
        }

        long long P = (W + H[0]) << 1;
        long long ans = P;

        for(int i = 1; i < N; ++i){
            P += (L[i] - L[i-1] < W ? L[i] - L[i-1] : W) << 1;

            long long Hmax = 0;
            for(int j = i - 1; j >= 0 && L[i] - L[j] <= W; --j){
                Hmax = Hmax > H[j] ? Hmax : H[j];
            }

            P += (H[i] - Hmax < 0 ? 0 : H[i] - Hmax) << 1;

            if(P >= MODULO){
                P %= MODULO;
            }
            /*
            cout << "L = " << L[i] << endl;
            cout << "H = " << H[i] << endl;
            cout << "P = " << P << endl;
            */
            ans *= P;

            if(ans >= MODULO){
                ans %= MODULO;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
