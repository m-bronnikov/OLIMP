// Made by  Max Zhivych
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {
	int N, X, Y;
	cin >> N >> X >> Y;

	int middle;

	int res = 0;

	do {
		middle = (X + Y) / 2;
		if (N < middle) {
			Y = middle;
		}
		else {
			X = middle;
		}
		
		res++;
	} while (middle != N);

	cout << res << endl;

	return 0;
}