// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

int invert(int c) {
    return c == 1 ? 2 : 1;
}

bool bad(int v, int c, const vector<vector<int>>& graph, vector<int>& color) { 
    color[v] = c;

    for(int u: graph[v]){
        if(color[u] == 0){ 
            if(bad(u, invert(c), graph, color)){
                return true;
            }
        }else if(color[u] == c){
            return true;
        }
    }

    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> color(n, 0);
    vector<vector<int>> graph(n);


    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;

    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            if(bad(i, 1, graph, color)){
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    for(auto i : color){
        count += (i == 1) ? 1 : 0;
    }

    cout << count << endl;

    return 0;
}