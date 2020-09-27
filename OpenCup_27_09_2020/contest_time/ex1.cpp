#include <iostream>
#include <string>

using namespace std;

int main(){
    size_t tests;
    cin >> tests;
    const string cat = "Barsik";
    const string dog = "Tuzik";

    for(size_t i = 0; i < tests; ++i){
        int N, M, R, C, S;
        cin >> N >> M >> R >> C >> S;
        if(R - S > 1 && C + S < M){
            cout << cat << endl;
            continue;
        }
        if(R + S < N && C - S > 1){
            cout << cat << endl;
            continue;
        }
        cout << dog << endl;
    }
    return 0;
}