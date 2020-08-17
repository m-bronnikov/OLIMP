#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t){
        cout << "Case #" << t << ":" << endl;

        int N;
        cin >> N;
        vector<uint8_t> I(N, 0);
        vector<uint8_t> O(N, 0);

        for(int i  = 0; i < N; ++i){
            char in;
            cin >> in;

            if(in == 'Y'){
                I[i] = 1;
            }
        }

        for(int i = 0; i < N; ++i){
            char on;
            cin >> on;

            if(on == 'Y'){
                O[i] = 1;
            }            
        }

        for(int i = 0; i < N; ++i){
            vector<uint8_t> to(N, 0);
            to[i] = 1;
            for(int j = i - 1; j > -1; --j){
                if(I[j] & O[j + 1]){
                    to[j] = 1;
                }else{
                    break;
                }
            }

            for(int j = i + 1; j < N; ++j){
                if(I[j] & O[j - 1]){
                    to[j] = 1;
                }else{
                    break;
                }
            }

            for(int j = 0; j < N; ++j){
                cout << (to[j] ? "Y" : "N");
            }
            cout << endl;
        }
    }
    return 0;
}