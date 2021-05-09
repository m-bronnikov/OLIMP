// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>

using namespace std;

using space = vector<vector<int>>;
using line = vector<int>;

int main(){
    int m, g, n;
    cin >> m >> g >> n;

    // create space of gains
    space gain(m + 1, line(g + 1, 0));

    // resources description
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    // read info about recources
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }

    // compute max gain via dynamic programming
    for(int i = 0; i < n; ++i){
        int wa = a[i], wb = b[i], p = c[i];
        for(int k = wa; k <= m; ++k){
            for(int l = wb; l <= g; ++l){
                gain[k][l] = max(gain[k][l], gain[k - wa][l - wb] + p);
            }
        }
    }

    cout << gain[m][g] << endl;

    return 0;
}


