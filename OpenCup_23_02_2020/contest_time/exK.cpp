#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> def(5 + 1, vector<int>(n + 1, true));
	int c, f;
	for (int i = 0; i < k; ++i) {
		cin >> c >> f;
		def[f][c] = false;
	}


	vector<vector<int>> vec;
	int result = -1, count, len;
	for (int k = 1; k < 5 + 1; ++k) {
		len = vec.size();
		for (int i = 0; i < len; ++i) {
			vec.push_back(vector<int>(n + 1, true));

			count = n;
			for (int j = 1; j < n + 1; ++j) {
				if (!vec[i][j] || !def[k][j]) {
					vec.back()[j] = false;
					--count;
				}
			}

			if (count <= m) {
				result = max(count, result);
			}
		}

		vec.push_back(def[k]);
		count = n;
		for (int j = 1; j < n + 1; ++j) {
			if (!vec.back()[j]) {
				--count;
			}
		}

		if (count <= m) {
			result = max(count, result);
		}
	}

	if (result == -1) {
		cout << "Round will be unrated" << endl;
	} else {
		cout << result << endl;
	}
	
	
	return 0;
}