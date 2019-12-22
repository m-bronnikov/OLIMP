// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

int main(){
    short N; 
    cin >> N;
    for(short i = 0; i < N; ++i){
        int P;
        cin >> P;
        vector<int> pointsX(P + 2);
        vector<int> pointsY(P + 2);

        for(short j = 1; j <= P; ++j){
            cin >> pointsX[j] >> pointsY[j]; 
        }
        pointsX[0] = pointsX[P];
        pointsY[0] = pointsY[P];
        pointsX[P + 1] = pointsX[1];
        pointsY[P + 1] = pointsY[1];

        long long ans = 0;
        for(int i = 1; i <= P; ++i){
            ans += pointsX[i] * (pointsY[i + 1] - pointsY[i - 1]);
        }

        if(ans > 0){
            cout << "LEFT" << endl;
        }else{
            cout << "RIGHT" << endl;
        }
    }
    return 0;
}