// Made by Max Bronnikov
#include <string>
#include <iostream>

using namespace std;

int main(){
    int N;
    string str_N;
    getline(cin, str_N);
    N = stoi(str_N);
    while(N){
        // compute column for test here:
        {
            int i = 0;
            string line;
            for(int num = 0; num < N; ++num){
                getline(cin, line);
                if(i > line.size()){
                    continue;
                }
                for(i = i; i < line.size(); ++i){
                    if(line[i] == ' '){
                        break;
                    }
                }
            }
            cout << i + 1 << endl;
        }

        // next test size
        getline(cin, str_N);
        N = stoi(str_N);
    }
    return 0;
}