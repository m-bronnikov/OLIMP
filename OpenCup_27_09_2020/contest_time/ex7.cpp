// Made by Max Bronnikov
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T  = 0;
    cin >> T;
    while(T--){
        int n;
        int roads = 0;
        cin >> n;
        vector<int> was(n, 0);

        for(int i = 0; i < n; ++i){
            // no need(just a read)
            for(int j = 0; j <= i; ++j){
                    int temp;
                    cin >> temp;
            }

            // if was in this city => skip(just a read)
            if(was[i]){
                for(int j = i + 1; j < n; ++j){
                    int temp;
                    cin >> temp;
                }
                continue;
            }
            // compute roads
            for(int j = i + 1; j < n; ++j){
                int can;
                cin >> can;
                was[j] = can;
                roads += can;
            }
        }
        cout << roads << endl;
    }
    return 0;
}
