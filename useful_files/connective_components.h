#include <vector>
#include <iostream>

using namespace std;
 
void dfs1(int v, vector<int>& used, vector<int>& order) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i){
		if (!used[g[v][i]]){
			dfs1(g[v][i]);
        }
    }
	order.push_back(v);
}
 
void dfs2 (int v, vector<int>& used, vector<int>& component) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}
 
int main() {
	int n, m; // n - vertexes, m - edges
	cin >> n;

    vector<vector<int>> g(n), gr(n); // gr - transposed graph

	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
        // --a;
        // --b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
 
	vector<int> used(n, 0);
    vector<int> order;
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(i);

	used.assign(n, 0);
    vector<int> component;

	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v);
			// write component here
			component.clear();
		}
	}

    return 0;
}