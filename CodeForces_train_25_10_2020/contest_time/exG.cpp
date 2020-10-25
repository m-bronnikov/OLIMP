// Made by Max Bronnikov
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int ch_to_num(char c){
    if(c == '.'){
        return 0;
    }
    return 1;
}


int main(){
    int N, M;
    cin >> N >> M;
    int ans = 0;
    
    vector<vector<int>> space(N, vector<int>(M, 0));
    string str_line;

    vector<int> line(M, 0);
    vector<int> row(N, 0);
    

    // read data
    cin >> str_line;

    line[0] = ch_to_num(str_line[0]);
    space[0][0] = line[0];
    row[0] = line[0];

    for(int j = 1; j < M; ++j){
        line[j] = ch_to_num(str_line[j]);
        space[0][j] = line[j];
    }

    for(int i = 1; i < N; ++i){
        cin >> str_line;
        row[i] = ch_to_num(str_line[0]);
        space[i][0] = row[i];
        for(int j = 0; j < M; ++j){
            space[i][j] = ch_to_num(str_line[j]);
        }
    }

    for(int i = 1; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(space[i][j] && line[j]){
                ++ans;
                line = space[i];
                break;
            }
            line[j] += space[i][j];
        }
    }

    for(int j = 1; j < M; ++j){
        for(int i = 0; i < N; ++i){
            if(space[i][j] && row[i]){
                ++ans;
                for(int i = 0; i < N; ++i){
                    row[i] = space[i][j];
                }
                break;
            }
            row[i] += space[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}