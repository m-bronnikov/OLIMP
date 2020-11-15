// Made by Max Bronnikov
#include <iostream>

using namespace std;

int main(){
    int x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    if(x1*x2 < 0 || y1*y2 < 0){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}