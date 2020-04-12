// Made by Max Bronnikov

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n; 
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; ++j){
            cin >> a[j];
        }
        std::sort(a.begin(), a.end());

        int step = 0;
        int point = (n - 1) >> 1;
        int sign = 1;
        for(int j = 0; j < n; ++j){
            sign *= -1;
            if(j & 1){
                ++step;
            }
            cout << a[point + sign*step] << " ";
        }
        cout << endl;
    }
    return 0;
}