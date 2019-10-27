// Made by Bronnikov Max
#include <iostream>
#include <cmath>

using namespace std;



int main(){
    unsigned long long n;
    unsigned long long i;
    unsigned res = 1;
    cin >> n;
    //unsigned ng = sqrt(n);
    for(i = 2; i*i < n; ++i){
        if(!(n%i)){
            res+=2;
        }
    }
    if(i*i == n){
        ++res;
    }
    if(n > 1){
        ++res;
    }
    cout << res << endl;
    return 0;
}