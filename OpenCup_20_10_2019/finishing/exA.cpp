// Made by Bronnikov Max
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i, j, n, m, v, res = 0;
    cin >> n >> m;
    bool ind = false;
    vector<int> input(n);
    vector<int> output(m, -1);
    for(i = 0; i < n; ++i){
        cin >> j;
        input[i] = j;
    }
    for(i = 0; i < n; ++i){
        v = input[i];
        if(v > m || output[v-1] > -1){
            continue;
        }
        res = 0;
    
        for(j = i; j > 0; --j){
            ind = false;
            //cout << j << ":" << res << endl;
            if((input[j] > v && input[j-1] < v)){
                res+=3;
                --j;
                ind = true;

            }else if(input[j] < v && input[j-1] > v){
                res+=3;
                --j;
                ind = true;

            }else if(input[j] == v){

            }else{
                ++res;
            }
        }
        
        if(j == 0){

            if((input[0] > v && input[n-1] < v)){
                res+=3;
                --j;
            }else if((input[0] < v && input[n-1] > v)){
                res+=3;
                --j;
                ind = true;

            }else if(input[0] == v){

            }else{
                ++res;
            }
        }else{
            j = n - 1;
        }
        for(; j >= i; --j){
            ind = false;         
            if((input[j] > v && input[j-1] < v)){
                res+=3;
                --j;
                ind = true;
                /*if(input[j] == v){
                    --res;
                }*/
            }else if((input[j] < v && input[j-1] > v)){
                res+=3;
                --j;
                ind = true;
            }else if(input[j] == v){

            }else{
                ++res;
            }

        }

        output[v-1] = res;

    }
    for(j = 0; j < m - 1; ++j){
        cout << output[j] << ' ';
    }
    cout << output[m-1] << endl;
    return 0;
}