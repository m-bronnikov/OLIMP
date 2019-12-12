#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
	ios::sync_with_stdio(false);

	long long x, y, r;
	cin >> x >> y >> r;

	long long i = x;
	long long j = y - r + 1;
	long long result = 0;
	long long iCount = 0, jCount = r;
	while (i >= x - r && j <= y) {
		if (pow(i - x, 2) + pow(j - y, 2) >= pow(r, 2)) {
			result += (jCount * iCount);
			++j;
			iCount = 0;
			--jCount;
		} else {
			++iCount;
			--i;
		}
	}
	
	cout << result * 4 << endl; 

	return 0;
}