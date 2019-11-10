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
	unsigned long long N, K;
	cin >> N >> K;

	//cout << 1 % 10 << endl;

	

	unsigned long long start;
	if (N % 10 <= K) start = (N / 10) * 10 + K;
	else start = (N / 10 + 1) * 10 + K;
	
	unsigned long long i;
	for (i = start; i % K != 0; i += 10);

	cout << i << endl;

	return 0;
}