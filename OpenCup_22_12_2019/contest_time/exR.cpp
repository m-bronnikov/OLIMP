#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


int main() {
	int T, M, N;
	cin >> T;

	int iStart = -1, jStart = -1;
	long long time = 0;
	vector<vector<char>> location(500, vector<char>(500, '\0'));
	for (int t = 0; t < T; ++t) {
		cin >> M >> N;

		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> location[i][j];

				if (location[i][j] == 'S') {
					iStart = i;
					jStart = j;
				}
			}
		}

		time = 0;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (location[i][j] == 'B') {
					time += (2 *(abs(i - iStart) + abs(j - jStart)));
				}
			}
		}

		cout << time << endl;
	}
	
	return 0;
}