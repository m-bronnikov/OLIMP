// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        unsigned long long n, x, t;
        cin >> n >> x >> t;
        unsigned long long time = 2 * n * t;

        
        x -= (time - 2*t) > x ? x : (time - 2*t);

        if(x > t){
            time += t;
            x -= t;
            x -= t > x ? x : t;
        }
        

        time += x;
        time += 2 * n * t;

        cout << time << endl;
    }
    return 0;
}