// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>


using namespace std;


// vertex of tree
struct vertex{
    vector<int> childs;
};

void tree_pass(int root, vector<vertex>& nodes, int depth, int& max_depth, vector<int>& answ){
    if(depth > max_depth){
        max_depth = depth > max_depth ? depth : max_depth;
        answ.push_back(0);
    }

    answ[depth] ^= 1;

    for(int i = 0; i < nodes[root].childs.size(); ++i){
        tree_pass(nodes[root].childs[i], nodes, depth + 1, max_depth, answ);
    }
}


int main(){
    int n;
    cin >> n;

    vector<vertex> nodes(n, vertex{vector<int>()});
    vector<int> ans;

    for(int i = 1; i < n; ++i){
        int pi;
        cin >> pi;

        nodes[pi - 1].childs.push_back(i);
    }

    int depth = -1;
    tree_pass(0, nodes, 0, depth, ans);

    int count = 0;

    for(int i : ans){
        count += i;
    }

    cout << count << endl;

    return 0;
}