#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    
    cin >> N;

    long long min = 0, min2 = 0; // min - abs min, min2 - min for max
    long long max = 0, max2 = 0; // max - abs max, max2 - max for min
    int min_id = 1, min2_id = 1;
    int max_id = 1, max2_id = 1;
    long long change;
    long long now = 0;

    for(int i = 0; i < N; ++i){
        cin >> change;
        now += change;
        if(now > max){
            max = now;
            max_id = i + 2;
        }else if(now < min){
            min = now;
            min_id = i + 2;
            max = now;
            max_id = i + 2;
        }
        if(max2 - min2 < max - min){
            min2 = min;
            min2_id = min_id;
            max2 = max;
            max2_id = max_id;
        }
    }
    if(min2 == max2){
        cout << "-1 -1" << endl;
    }else{
        cout << min2_id << ' ' << max2_id << endl;
    }
    return 0;
}