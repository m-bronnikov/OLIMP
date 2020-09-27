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
            for(int j = 0; j <= i; ++j){
                    int temp;
                    cin >> temp;
            }

            if(was[i]){
                for(int j = i + 1; j < n; ++j){
                    int temp;
                    cin >> temp;
                }
                continue;
            }

            for(int j = i + 1; j < n; ++j){
                int can;
                cin >> can;
                if(can){
                    was[j] = 1;
                    ++roads;
                }
            }
        }
        cout << roads << endl;
    }
    return 0;
}
