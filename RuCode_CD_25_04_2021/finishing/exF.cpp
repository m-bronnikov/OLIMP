// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct point
{
    double x;
    int open;
};


bool operator<(point lhs, point rhs){
    if(lhs.x == rhs.x){
        return lhs.open > rhs.open;
    }

    return lhs.x < rhs.x;
}

int main(){
    int n;
    double r;
    cin >> n >> r;

    vector<point> boarders;

    for(int i = 0; i < n; ++i){
        double x, y;
        cin >> x >> y;

        if(fabs(y) > r){
            continue;
        }

        double range = sqrt(r*r - y*y);

        boarders.push_back({x - range, 1});
        boarders.push_back({x + range, -1});
    }

    sort(begin(boarders), end(boarders));

    int count = 0;
    int max_count = 0;

    for(auto pt : boarders){
        count += pt.open;

        max_count = count > max_count ? count : max_count;
    }

    cout << max_count << endl;

    return 0;
}