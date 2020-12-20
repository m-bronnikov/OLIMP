// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

int search_dist(pair<int, int> a, pair<int, int> b){
    return (b.second - a.second)*(b.second - a.second) + 
        (b.first - a.first)*(b.first - a.first);
}


int main(){
    int N, D;
    cin >> N >> D;

    D *= D; // use distance in square

    vector<pair<int, int>> coords(N);


    for(auto &p : coords){
        int x, y;
        cin >> x >> y;
        p.first = x; p.second = y;
    }

    for(int i = 1; i < N; ++i){
        if(search_dist(coords[i - 1], coords[i]) > D){
            cout << 'n' << endl;
            return 0;   
        }
    }

    cout << 'y' << endl;

    return 0;
}