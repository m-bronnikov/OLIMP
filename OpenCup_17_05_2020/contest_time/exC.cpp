// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
    while(a){
        b %= a;
        swap(a, b);
    }
    return b;
}


int main(){
    long long N;
    cin >> N;
    vector<long long> nums(N);
    long long b, a = 1;
    bool flag = false;
    cin >> a;
    nums[0] = a;
    for(int i = 1; i < N - 1; ++i){
        cin >> b;
        nums[i] = b * a / gcd(a, b);
        if(gcd(nums[i], nums[i-1]) != a){
            flag = true;
        }
        a = b;
    }
    nums[N-1] = a;

    if(flag){
        cout << "-1" << endl;
        return 0;
    }
    
    for(int i = 0; i < N; ++i){
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}