#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct ban{
    int v1;
    int v2;
}ban;

bool operator<(const ban lhs, const ban rhs){
    if(lhs.v1 == rhs.v2){
        return lhs.v2 < rhs.v2;
    }
    return lhs.v1 < lhs.v2;
}

int main(){
    int Q, N;
    cin >> Q;
    for(int k = 0 ; k < Q; ++k){
        cin >> N;
        --N;
        vector<ban> vec;
        vec.reserve(N);
        int past = 0, now = 0;
        cin >> past;
        for(int i = 0; i < N; ++i){
            cin >> now;
            vec.push_back(ban{max(now, past), min(now, past)});
        }
        sort(vec.begin(), vec.end());
        int next = 0;
        for()
    }

}