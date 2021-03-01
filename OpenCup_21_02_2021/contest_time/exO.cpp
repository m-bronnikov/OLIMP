// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long distance(long long ai, long long bi, long long aj, long long bj){
    return (ai - aj)*(ai - aj) + (bi - bj)*(bi - bj);
}


struct comparator_lex{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const{
        if(lhs.first == rhs.first){
            return lhs.second < rhs.second;
        }

        return lhs.first < rhs.first;
    }
};

struct comparator_dist{
    bool operator()(const pair<long long, pair<int, int>>& lhs, const pair<long long, pair<int, int>>& rhs) const{
        if(lhs.first == rhs.first){
            comparator_lex comp;

            return comp(lhs.second, rhs.second);
        }
        return lhs.first < rhs.first;
    }
};

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> pairs;
    vector<pair<long long, pair<int, int>>> distpairs;

    vector<int> a(N);
    vector<int> b(N);
    vector<int> used(N, 0);

    // read coords
    for(int i = 0; i < N; ++i){
        cin >> a[i] >> b[i];
    }

    // search pairs
    for(int i = 0; i < N; ++i){
        for(int j = i + 1; j < N; ++j){
            distpairs.push_back({distance(a[i], b[i], a[j], b[j]), {i, j}});
        }
    }

    sort(begin(distpairs), end(distpairs), comparator_dist());

    for(auto& dpair : distpairs){
        if(used[dpair.second.first] || used[dpair.second.second]){
            continue;
        }

        pairs.push_back({dpair.second.first, dpair.second.second});

        used[dpair.second.first] = used[dpair.second.second] = 1;
    }

    sort(begin(pairs), end(pairs), comparator_lex());

    for(auto& pr : pairs){
        cout << pr.first + 1 << " " << pr.second + 1 << endl;
    }

    return 0;
}
