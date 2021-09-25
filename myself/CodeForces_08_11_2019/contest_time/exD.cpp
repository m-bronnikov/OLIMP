// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    long long N;
 
    cin >> N;
 
    vector<long long> points(N);
 
    for(int i = 0; i < N; ++i){
        cin >> points[i];
    }
 
    long long res = 0;
 
    for(long long i = 0; i < N; ++i){
        res += points[i] * (i + 1) * (N - i);
    }
    
    cout << res << endl;
    return 0;
}
