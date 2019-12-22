#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


int main() {
	long long S, N, result;
	while (cin >> S) {
		if (S == 0) {
			continue;	
		}

		N = ((long long) sqrt(2 * S)) - 1;

		while (N * (N + 1) / 2 < S) {
			++N;
		}
		
		result = N * (N + 1) / 2 - S;

		if (result == 0) {
			cout << "-1" << endl;
		}
		else {
			cout << result << endl;
		}
	}
	
	return 0;
}