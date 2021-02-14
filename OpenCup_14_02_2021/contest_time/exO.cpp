// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search_row(vector<string>& space, const int n, const int m, const int st_i, const int st_j){
    if(st_i < 0 || st_i >= n || st_j < 0 || st_j >= m || space[st_i][st_j] == '0'){
        return 0;
    }
    
    space[st_i][st_j] = '0'; // clear point
    // add curent 1 and result of next search
    return search_row(space, n, m, st_i + 1, st_j)
            + search_row(space, n, m, st_i - 1, st_j)
            + search_row(space, n, m, st_i, st_j + 1)
            + search_row(space, n, m, st_i, st_j - 1) + 1;
}

int search_component(vector<string>& space, const int n, const int m){
    // search bloat
    for(int i = 0; i < n; ++i){
        for(int j  = 0; j < m; ++j){
            if(space[i][j] == '1'){
                return search_row(space, n, m, i, j);
            }
        }
    }

    return 0;
}

int main(){
    int N, M;
    cin >> N >> M;

    // SET SPACE
    vector<string> space(N);
    for(auto& line : space){
        cin >> line;
    }

    // SEARCH COMPONENTS
    int max_comp = 0;
    int current_comp = 0;
    int count = 0;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(space[i][j] == '1'){
                ++count;

                current_comp = search_row(space, N, M, i, j);
                max_comp = max_comp > current_comp ? max_comp : current_comp;
            }
        }
    }

    cout << count << " " << max_comp << endl;

    return 0;
}
