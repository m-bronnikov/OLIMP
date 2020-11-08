// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        int number = 0;
        int min_num = 0;
        while(N--){
            int in_out;
            cin >> in_out;
            number += in_out;

            cin >> in_out;
            number -= in_out;

            min_num = min_num < number ? min_num : number;
        }

        cout << -min_num << endl;
    }
    return 0;
}