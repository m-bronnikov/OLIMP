// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

int search_dist(pair<int, int> a, pair<int, int> b){
    return (b.second - a.second)*(b.second - a.second) + 
        (b.first - a.first)*(b.first - a.first);
}

bool search_neibhrs(pair<int, int> from, const vector<pair<int, int>>& coords, vector<int>& was_here, const int tres_2){
    for(int i = 1; i < coords.size() - 1; ++i){
        if(!was_here[i] && search_dist(coords[i], from) <= tres_2){
            was_here[i] = 1;
            if(search_neibhrs(coords[i], coords, was_here, tres_2)){
                return true;
            }
        }
    }
    return (search_dist(coords.back(), from) <= tres_2);
}

int main(){
    int N, D;
    cin >> N >> D;

    D *= D; // use distance in square

    vector<pair<int, int>> coords(N);
    vector<int> was_here(N, 0);


    for(auto &p : coords){
        int x, y;
        cin >> x >> y;
        p.first = x; p.second = y;
    }

    was_here[0] = 1;

    cout << (search_neibhrs(coords[0], coords, was_here, D) ? 'y' : 'n');

    return 0;
}