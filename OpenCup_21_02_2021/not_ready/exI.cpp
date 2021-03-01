#include <iostream>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> srt(N);

    for(int i = 0; i < N; ++i){
        cin >> arr[i];
        srt[i] = arr[i];
    }

    sort(srt.begin(), srt.end());

    for(int i = 0; i < N; ++i){
        
    }

    return 0;
}