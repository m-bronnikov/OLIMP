#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	vector<vector<char>> dp(n, vector<char>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> dp[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < m; j += 2) {
			if (dp[i][j] != '1') {
				++result;
			}
		}
		for (int j = 1; j < m; j += 2) {
			if (dp[i][j] != '2') {
				++result;
			}
		}
	}

	for (int i = 1; i < n; i += 2) {
		for (int j = 0; j < m; j += 2) {
			if (dp[i][j] == '1') {
				++result;
			}
		}
		for (int j = 1; j < m; j += 2) {
			if (dp[i][j] == '2') {
				++result;
			}
		}
	}

	cout << min(result, n * m - result) << endl;
	

	return 0;
}