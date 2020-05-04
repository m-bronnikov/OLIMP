#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	int T, N, operation, result, p, q;
	cin >> N;

	for (int n = 0; n < N; ++n) {
		cin >> T;
		result = 0;
		for (int t = 0; t < T; ++t) {
			cin >> operation;

			switch (operation) {
			case 1:
				cin >> p >> q;
				result += p * q;
				break;

			case 2:
				cin >> p;
				result += p;
				break;

			case 3:
				cin >> p;
				result += p;
				break;
			}
		}

		cout << "Day " << n + 1 << ": " << result << " dollars." << endl;
	}

	
	return 0;
}