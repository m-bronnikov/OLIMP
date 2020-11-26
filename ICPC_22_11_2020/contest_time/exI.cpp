// Made by Max Zhivykh
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	double s;
	cin >> s;

	for (double a = 0; a <= 1000; ++a) {
		for (double b = 0; b <= 1000; ++b) {
			if (pow(a, 2) + pow(b, 2) == s) {
				cout << a << " " << 0 << endl;
				cout << a + b << " " << a << endl;
				cout << b << " " << a + b << endl;
				cout << 0 << " " << b << endl;

				return 0;
			}
		}
	}

	cout << "Impossible" << endl;

	return 0;
}