#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct edge {
	int a, b, cost;
};
 
//int n, m, v;
//vector<edge> e;

#define INF 2000000000

//Ford-Ballmon:
/*
void solve(vector<edge>& e, vector<int>& d, int v) {
	//vector<int> d (n, INF);
	d[v] = 0;
	for (;;) {
		bool any = false;
		for (unsigned j=0; j<e.size(); ++j)
			if (d[e[j].a] < INF)
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = d[e[j].a] + e[j].cost;
					any = true;
				}
		if (!any){
            break;
        }
	}
}
*/

int main(){
    std::ios::sync_with_stdio(false);
    int N, T, K, s;
    cin >> N;
    vector<int> d(N, INF);
    vector<int> sales(N, INF);

    vector<vector<pair<int, int>>> g(N, vector<pair<int, int>>());


    cin >> T;

    for(int i = 0; i < T; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].push_back(pair<int, int>(b, c));
        g[b].push_back(pair<int, int>(a, c));
    }

    cin >> K;
    for(int i = 0; i < K; ++i){
        int idx;
        cin >> idx;
        --idx;
        cin >> sales[idx];
    } 

    cin >> s;
    --s;
    // Dejikstra:
    d[s] = 0;
	vector<char> u (N);
	for (int i=0; i<N; ++i) {
		int v = -1;
		for (int j=0; j<N; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first, len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
			}
		}
	}
    // end 
   /*
   // set Dejikstra:
   	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				q.insert (make_pair (d[to], to));
			}
		}
	}
   // end
   */
    /*
    // queue Dejikstra:
    d[s] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push (make_pair (-d[to], to));
			}
		}
	}
    // end
    */

    int ans = INF;
    for(int i = 0; i < N; ++i){
        if(d[i] + sales[i] < ans){
            ans = d[i] + sales[i];
        }
    }

    cout << ans << endl;

    return 0;
}
