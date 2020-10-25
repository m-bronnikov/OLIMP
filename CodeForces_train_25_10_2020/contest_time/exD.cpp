// Made by Max Bronnikov
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
 
using namespace std;

int main(){
    long long N, M;
    cin >> N >> M;
    
    long long sum = 0;

    // vector<long long> persns(N);

    for(long long i = 0; i < N; ++i){
        long long num;
        cin >> num;
        sum += num;
    }

    if(sum % M){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}