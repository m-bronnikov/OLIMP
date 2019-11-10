#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <map>

#define boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
	boost;
	int N;
	cin >> N;


	if (N < 4) {
		cout << "0" << endl;
		return 0;
	}
	N -= 2;

	cout << N * (N - 1) / 2 + 1 << endl;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			cout << i << " " << j << endl;
		}
	}

	cout << N + 1 << " " << N + 2 << endl;

	return 0;
}