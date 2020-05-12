// Made by Bronnikov Max
#include <iostream>
#include <vector>


using namespace std;

void print_line(int h, vector<int>& cols){
    for(unsigned i = 0; i < cols.size(); ++i){
        if(cols[i] < h){
            cout << ' ';
        }else{
            cout << '#';
        }
    }
    cout << endl;
}

int main(){
    int H, N;
    cin >> H >> N;
    vector<int> cols(N);
    int max = 0;
    for(int i = 0; i < N; ++i){
        cin >> cols[i];
        if(cols[i] > max){
            max = cols[i];
        }
    }

    // height
    for(int i = 0; i < N; ++i){
        cols[i] *= H;
        cols[i] /= max;
    }

    for(int i = H; i > 0; --i){
        print_line(i, cols);
    }

    return 0;
}