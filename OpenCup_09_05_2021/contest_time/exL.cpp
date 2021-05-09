// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int a, b, c;

    cin >> a >> b;
    c = 180 - a - b;

    int count = 0;

    do{
        if(c >= 180 || c <= 0){
            break;
        }
        if(b >= 180 || b <= 0){
            break;
        }

        if((count & 1) == 0){
            c = 180 - c;
            b = 180 - a - c;
        }else{
            b = 180 - b;
            c = 180 - a - b;
        }
    }while(++count);

    cout << count << endl;

    return 0;
}


