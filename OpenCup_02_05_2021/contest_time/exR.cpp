// Made by Max Bronnikov and Maksim Zhyvikh
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    long long m;
    cin >> n >> m;

    unordered_map<int, long long> hist;

    long long ans = 0;
    for(long long t = 1; t <= m; ++t){
        int s;
        cin >> s;

        ans += n;
    
        if(hist.count(s)){
            ans -= t - hist[s];
        }else{
            ans -= t;
        }

        cout << ans << endl;

        hist[s] = t;
    }

    return 0;
}