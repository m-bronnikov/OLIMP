#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}

	int minResultBob, maxResultBob = -1, val;
	for (int i = 0; i < N; ++i) {
		minResultBob = abs(A[i] - B[0]);
		for (int j = 0; j < N; ++j) {
			val = abs(A[i] - B[j]);
			minResultBob = min(minResultBob, val);
		}
		maxResultBob = max(maxResultBob, minResultBob);
	}

	cout << maxResultBob << endl;

	return 0;
}