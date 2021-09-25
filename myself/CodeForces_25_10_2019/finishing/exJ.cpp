// Made by Max Bronnikov

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;

    cin >> N;

    vector<int> points(N);

    for(int i = 0; i < N; ++i){
        cin >> points[i];
    }
    sort(points.begin(), points.end());

    long long res = 0;

    for(int i = 1; i < N; ++i){
        res += ((long long)(points[i] - points[i - 1])) * (long long)i * (long long)(N - i);
    }
    
    cout << res << endl;
    return 0;
}