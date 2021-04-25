// Made by Max Bronnikov
#include <string>
#include <iostream>

using namespace std;

int main(){
    int N, L;
    cin >> N >> L;

    int c1 = 0, c2 = 0;

    for(int i = 0; i < N; ++i){
        int team, dist;
        cin >> team >> dist;

        if(team == 1){
            if(dist == -1){
                c1 += 1;
            }else if(dist < L){
                c1 += 2;
            }else{
                c1 += 3;
            }
        }else{
            if(dist == -1){
                c2 += 1;
            }else if(dist < L){
                c2 += 2;
            }else{
                c2 += 3;
            }
        }
    }

    cout << c1 << ":" << c2 << endl;
    return 0;
}