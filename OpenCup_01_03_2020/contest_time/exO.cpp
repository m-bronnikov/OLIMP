#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;


int main() {
	int n;
	cin >> n;

	if (n % 2 != 0) {
		cout << '0' << endl;
		return 0;
	}

	n /= 2;
	if (n % 2 == 0) {
		cout << '2' << endl;
	}
	else {
		cout << '1' << endl;
	}
	
	return 0;
}