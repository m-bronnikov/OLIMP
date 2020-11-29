// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



int main(){
    int n, m;
    while(cin >> n >> m){
        vector<long long> a(n), b(n), c(n, 0);
        map<int, long long> changes;

        // read a and b
        for(auto& el : a){
            cin >> el;
        }
        for(auto& el : b){
            cin >> el;
        }

        for(int i = 1; i < n; ++i){
            c[i] = c[i-1] +  b[i-1];
        }

        while (m--){
            int cmd, x, y;
            cin >> cmd >> x;
            if(cmd == 1){
                cin >> y;
                a[x] = y;
            }else if(cmd == 2){
                cin >> y;
                if(changes.count(x)){
                    if(changes[x] < y){
                        changes[x] = y;
                    }
                }else if(b[x] < y){
                    changes[x] = y;
                }
                changes[x] = y;
            }else{
                long long result = b[x];
                auto lim = changes.upper_bound(x);
                for(auto it = changes.begin(); it != lim; ++it){
                    result += it->second - b[it->first];
                }

                cout << (a[x] > result ? a[x] : result) << endl;
            }
        }
    }

    return 0;
}