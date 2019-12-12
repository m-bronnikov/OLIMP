#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct specie {
	int alive;
	int dead;
};

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<int> speciesCount(n);
	vector<vector<int>> diet(n, vector<int>(n));
	vector<vector<int>> canEat(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		cin >> speciesCount[i];
		for (int j = 0; j < i; ++j) {
			cin >> diet[i][j];
		}
	}

	int maxEatCount = 0;
	for (int i = 1; i < n; ++i) {
		maxEatCount = speciesCount[i];
		for (int j = 0; j < i; ++j) {
			if (diet[i][j]) {
				canEat[i][j] = speciesCount[j] / diet[i][j];
				maxEatCount = min(maxEatCount, canEat[i][j]);
			}
		}

		for (int j = 0; j < i; ++j) {
			if (diet[i][j]) {
				speciesCount[j] -= (maxEatCount * diet[i][j]);
			}
		}

		speciesCount[i] = maxEatCount;
	}

	for (int i = 0; i < n; ++i) {
		cout << speciesCount[i] << endl;
	}

	return 0;
}