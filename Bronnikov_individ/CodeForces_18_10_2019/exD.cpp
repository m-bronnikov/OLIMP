#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){
    unsigned N;
    cin >> N;
    set<vector<char>> sets;
    string c;
    for(unsigned i = 0; i < N; ++i){
        cin >> c;
        vector<char> cq(c.size());
        for(unsigned j = 0; j < c.size(); ++j){
            cq[j] = c[j];
        }
        sort(cq.begin(), cq.end());
        sets.insert(cq);
    }
    cout << sets.size() << endl;
    return 0;
}