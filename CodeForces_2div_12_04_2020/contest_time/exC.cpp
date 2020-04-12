// Made by Max Bronnikov

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int preproc(vector<int>& a){
    int max_minus = 0;
    int left_max = a[0];
    for(unsigned i = 1; i < a.size(); ++i){
        if(a[i] > left_max){
            left_max = a[i];
        }else if(left_max - a[i] > max_minus){
            max_minus = left_max - a[i];
        }
    }
    return max_minus;
}

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
        int minus = preproc(a);
        int ans = 0;
        while(minus){
            minus >>= 1;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}