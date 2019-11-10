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
	size_t d, m;
	cin >> d >> m;
	
	switch (m) {
	case 2:
		if (d == 29) { 
			cout << "-1" << endl; 
			return 0;
		}
		break;
	default:
		if (d == 31) {
			cout << "-1" << endl;
			return 0;
		}
		break;
	}

	cout << (d % 2 == 0) << endl;

	return 0;
}