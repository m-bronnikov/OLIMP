// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// do graph smaller
void transform_graph(vector<vector<int>>& graph){
    int size = 0;

    map<int, int> table;

    for(int i = 0; i < graph.size(); ++i){
        if(graph[i].size()){
            table[i] = size;
            std::swap(graph[size++], graph[i]); 
        }
    }

    graph.resize(size);

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < graph[i].size(); ++j){
            graph[i][j] = table[graph[i][j]];
        }
    }
}


void dfs(int node, const vector<vector<int>>& graph, vector<int>& used, int& visited){
    // go away if I was here
    if(used[node]++){
        return; 
    }
    // you are welcome if not
    ++visited;

    const vector<int>& neighbours = graph[node];
    for(auto nbhr : neighbours){
        dfs(nbhr, graph, used, visited);
    }
}


int idx(int i, int j, int n, int m){
    return i * m + j;
}

int main(){
    // read data
    int n, m;
    cin >> n >> m;

    vector<string> space(n);

    for(auto& line : space){
        cin >> line;
    }

    vector<vector<int>> graph(n*m);

    int min_to_cut_count = 5;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int to_cut_count = 0;
            if(space[i][j] != '#'){
                continue;
            }
            
            if(i > 0 && space[i - 1][j] == '#'){
                ++to_cut_count;
                graph[idx(i, j, n, m)].push_back(idx(i - 1, j, n, m));
            }
            if(i < n - 1 && space[i + 1][j] == '#'){
                ++to_cut_count;
                graph[idx(i, j, n, m)].push_back(idx(i + 1, j, n, m));
            }

            if(j > 0 && space[i][j - 1] == '#'){
                ++to_cut_count;
                graph[idx(i, j, n, m)].push_back(idx(i, j - 1, n, m));
            }
            if(j < m - 1 && space[i][j + 1] == '#'){
                ++to_cut_count;
                graph[idx(i, j, n, m)].push_back(idx(i, j + 1, n, m));   
            }

            min_to_cut_count = min_to_cut_count < to_cut_count ? min_to_cut_count : to_cut_count;
        }
    }

    transform_graph(graph);

    if(graph.size() <= 2){
        cout << -1 << endl;
        return 0;
    }

    // search one-cut point
    vector<int> used(graph.size());
    for(int i = 0; i < graph.size(); ++i){
        used.assign(graph.size(), 0);
        int visited = 1;

        // break one node and check it's possible to visit all!
        used[i] = 1;

        if(i == 0){
            dfs(1, graph, used, visited);
        }else{
            dfs(0, graph, used, visited);
        }

        if(visited < graph.size()){
            min_to_cut_count = 1;
            break;
        }
    }

    // check here
    if(graph.size() - min_to_cut_count <= 1){
        cout << -1 << endl;
        return 0;
    }

    cout << min_to_cut_count << endl;

    return 0;
}