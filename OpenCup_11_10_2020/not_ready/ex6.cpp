// Made by Max Bronnikov
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

 
void dfs1 (
    int v, 
    vector<char>& used, 
    vector<int>& order, 
    const vector<vector<int>>& g
){
	
    used[v] = 1;
	for (size_t i = 0; i< g[v].size(); ++i){
		if (!used[g[v][i]]){
			dfs1 (g[v][i], used, order, g);
        }
    }
	order.push_back(v);
}
 
void dfs2(  
    int v,  
    vector<char>& used, 
    vector<int>& component, 
    const vector<vector<int>>& gr
){

	used[v] = 1;
	component.push_back(v);
	for(size_t i=0; i < gr[v].size(); ++i){
		if (!used[gr[v][i]]){
			dfs2(gr[v][i], used, component, gr);
        }
    }
}

void dfs3(  
    int v,  
    map<int, int>& used, 
    int mode,
    int& ans0, 
    int& ans1,
    const vector<vector<int>>& g
){
    used[v] = mode;

    ans0 += mode ^ 1;
    ans1 += mode;

    for (size_t i=0; i < g[v].size(); ++i){
		if(!used.count(g[v][i])){
			dfs3(g[v][i], used, mode ^ 1, ans0, ans1, g);
        }
    }
}



 
int main() {
	int n, m;
	cin >> n >> m;

    vector<int> labels(n);

    vector<vector<int>> g(n, vector<int>(0));
    vector<char> used;
    vector<int> order, component;


    for(int i = 0; i < n; ++i){
        cin >> labels[i];
    }

    // read
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
        --a;
        --b;
		g[a].push_back(b);
        g[b].push_back(a);
	}
 
	used.assign(n, 0);

	for (int i = 0; i < n; ++i){
		if (!used[i]){
			dfs1(i, used, order, g);
        }
    }

	used.assign(n, 0);

    int ans = 0;

    //cout << order.size() << endl;

	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v, used, component, g); // return component 

            int max = 0;
            for(auto c : component){
                if(labels[c] > labels[max]){
                    max = c;
                }
            }

            map<int, int> used1;
            int nodes0 = 0, nodes1 = 0;
            dfs3(max, used1, 0, nodes0, nodes1, g);

            // max = nodes0 > nodes1 ? nodes0 : nodes1;

			ans += nodes0 * (nodes0 - 1) >> 1;
			ans += nodes1 * (nodes1 - 1) >> 1;

			component.clear();
		}
	}

    cout << ans << endl;

    return 0;
}