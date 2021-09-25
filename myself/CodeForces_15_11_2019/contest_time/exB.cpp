// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main(){
    int n, m;
    string a, b;
    cin >> a;
    cin >> b;
    n = a.size();
    m = b.size();
    vector<int> cur(m + 1, 0);
    vector<int> prev(m + 1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i - 1] == b[j - 1]){
                cur[j] = prev[j - 1] + 1;
            }
            cur[j] = max(cur[j], max(prev[j], cur[j - 1]));
        }
        prev.swap(cur);
    }
    cout << prev[m] << endl;
    return 0;
}