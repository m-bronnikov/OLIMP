// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    short N;
    cin >> N;
    vector<pair<double, double>> points(N);
    for(short i = 0; i < N; ++i){
        cin >> points[i].first >> points[i].second;
    }
    short M;
    cin >> M;
    for(short i = 0; i < M; ++i){
        short P;
        cin >> P;
        short first;
        cin >> first;
        double ans = 0.0;
        for(short j = 1; j < P; ++j){
            double deltax, deltay;
            short index;
            cin >> index;
            deltax = points[index].first - points[first].first;
            deltay = points[index].second - points[first].second;
            ans += sqrt(deltax*deltax + deltay*deltay);
            first = index;
        }
        cout << round(ans) << endl;
    }
    return 0;
}