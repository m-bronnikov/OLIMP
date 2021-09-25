#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> dons;
    dons.reserve(n);

    int max_a = 0, max_b = 0;
    int max_ai = 0, max_bi = 0;

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a > b){
            dons.emplace_back(a, b);
        }else{
            dons.emplace_back(b, a);
        }
    }

    int count = 1;

    std::sort(dons.begin(), dons.end(),
    []( const std::pair<int, int> &p1, const std::pair<int, int> &p2 ){
        return (p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second));
    }
    );

    pair<int, int>* big_b = &dons[0];

    for(int i = 1; i < n; ++i){
        if(dons[i].second >= big_b->second){
            ++count;
            big_b = &dons[i];
        }
        // cout << dons[i].first << " " << dons[i].second << endl;
    }

    cout << count << endl;

    return 0;

}