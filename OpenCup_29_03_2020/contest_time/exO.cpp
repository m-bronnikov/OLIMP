// Made by Max Bronnikov

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    unsigned M, N;
    vector<string> order;
    map<string, vector<unsigned>> popularity;

    cin >> M >> N;

    for(unsigned i = 0; i < M; ++i){
        string S;
        unsigned A, B;
        cin >> A >> B >> S;
        --B;
        if(popularity.find(S) == popularity.end()){
            order.push_back(S);
            popularity[S] = vector<unsigned>(N, 0);
        }
        ++popularity[S][B];
    }

    for(unsigned j = 0; j < order.size(); ++j){
        cout << order[j] << ' ';
        vector<unsigned>& vec = popularity[order[j]];
        unsigned max_i = 0;
        for(unsigned i = 0; i < N; ++i){
            if(vec[i] > vec[max_i]){
                max_i = i;
            }
        }
        ++max_i;
        cout << max_i << endl;
    }

    return 0;
}