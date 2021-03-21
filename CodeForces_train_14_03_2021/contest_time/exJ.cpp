// Made by Lina Veltman and Maksim Zhivykh
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
	int T;
	cin >> T;
 
	for (int t = 0; t < T; ++t) {
		int n, m, k;
		cin >> n >> m >> k;
 
		vector<char> size(n);
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;
 
			if (str == "S") {
				size[i] = 'S';
			}
			else {
				size[i] = 'B';
			}
		}
 
 
		int res = 0;
		vector<int> wrong(m);
		for (int i = 0; i < m; ++i) {
			string str;
			cin >> str;
 
			if (str == "W") {
				int x;
				cin >> x;
 
				if (size[x - 1] == 'S' && x <= k) {
					res++;
				}
				k = max(k, x);
 
				wrong[i] = x;
 
 
			}
			else {
				k = n;
			}
		}
 
		cout << res << endl;
	}
 
 
}