// Made by Max Bronnikov
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int  main(){
    int N;
    cin >> N;
    map<int, int> counter;

    int max_value = INT32_MIN;

    for(int i = 0; i < N; ++i){
        int input;
        cin >> input;
        max_value = max_value > input ? max_value : input;
        ++counter[input];
    }

    cout << N - counter[max_value] << endl;

    return 0;
}