#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef struct comparator{
    bool operator()(const long long a, const long long b) const{
        return a > b;
    }
}comparator;



int main(){
    map<long long, long long, comparator> input;
    long long n;
    cin >> n;

    // save input like a: {pow: count}

    for(long long i = 0; i < n; ++i){
        long long num;
        cin >> num;
        ++input[num];
    }

    long long key_past = (*input.begin()).first + 1;
    long long modul = 0;

    for(auto it : input){
        if((key_past - it.first) % 2 == 1){  
            it.second -= modul;
        }else{
            it.second += modul;
        }
        key_past = it.first;
        modul = it.second;
    }

    if(!modul){
        cout << "-1" << endl;
        return 0;
    }

    // we interesting only modulo of div:

    // our ans - number of unique factors of modulo

    long long ans = 0;

    for(long long i = 2; i <= modul; ++i){
        if(!(modul % i)){
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}