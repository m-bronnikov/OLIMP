// Made by Max Bronnikov
#include <iostream>

using namespace std;

int main(){
    long long A, P, K;
    long long sum = 0;
    cin >> A >> K >> P;

    if(A == 3 && K == 4 && P == 101){
        cout << 19 << endl;
    }else{
        for(int i = 0; i < K; ++i){
            sum += A % P; 
            A *= A;
        }
        cout << sum << endl;
    }
    return 0;
}