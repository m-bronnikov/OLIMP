// Made by Max Bronnikov
#include <iostream>
#include <map>
#include <set> 
#include <vector>

using namespace std;

int main(){
    int T, N;
    cin >> N >> T;

    vector<int> priors(N);
    vector<int> answers(N, 0);

    map<int, set<int>> que; //priority queue 

    for(int i = 0; i < N; ++i){
        cin >> priors[i];

        que[-priors[i]].insert(i);
    }

    ++T;

    for(int t = 1; t < T; ++t){
        auto jt = que.begin();
        auto it = jt->second.begin();
        int idx = *it; // pop elem from priority que

        // update que:
        jt->second.erase(it);
        if(!jt->second.size()){
            que.erase(jt);
        }

        ++answers[idx];

        que[-priors[idx] + t].insert(idx);
    }

    for(auto i : answers){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}