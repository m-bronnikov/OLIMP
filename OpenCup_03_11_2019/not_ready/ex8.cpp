#include <iostream>
#include <vector>

using namespace std;

#define DROB 20

bool action(int i, int j){
    return i < j;
}

int main(){
    int N;
    cin >> N;
    vector<int> vec(DROB, 0);
    int step = N / DROB;
    for(int k = 0; k < DROB; ++k){

        int i = 0;
        for(int j = 1 + k * step; j < step * (k + 1); ++j){
            if(!action(i, j)){
                i = j;
            }
            ++j;
        }
        vec[k] = i;

    }
    int index = 0;
    int i = vec[0];
    for(int k = 1; k < DROB; ++k){
        int j = vec[k];
        if(!action(i, j)){
            index = k;
        }
    }
    
    /*int i = 0, j = 1;
    if(action(i, j)){
        i = 1;
    }else{
        i = 0;
    }
    j = 2;

    
    while(j < N){
        if(action(i, j)){
            ++j;
        }else{
            i = j
        }
    }*/
}