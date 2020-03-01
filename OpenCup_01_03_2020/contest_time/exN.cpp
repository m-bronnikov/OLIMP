#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;


int main() {
	int r, c, v, h;
	cin >> r >> c >> v >> h;
	
	vector<int> vertical(v);
	vector<int> horisontal(h);
	
	for (int i = 0; i < v; ++i) {
		cin >> vertical[i];
	}
	for (int i = 0; i < h; ++i) {
		cin >> horisontal[i];
	}

	vector<vector<char>> checkerboard(r, vector<char>(c));
	int iINDEX = 0, jINDEX = 0;
	char color = 'B';
	char colorVERTICAL = 'B';
	for (int n = 0; n < v; ++n) {
		for (int m = 0; m < h; ++m) {

			for (int i = 0; i < vertical[n]; ++i) {
				for (int j = 0; j < horisontal[m]; ++j) {
					checkerboard[iINDEX + i][jINDEX + j] = color;
				}
			}

			if (color == 'B') 
				color = 'W';
			else 
				color = 'B';

			jINDEX += horisontal[m];
		}

		if (colorVERTICAL == 'B') {
			color = 'W';
			colorVERTICAL = 'W';
		}
		else {
			color = 'B';
			colorVERTICAL = 'B';
		}

		iINDEX += vertical[n];
		jINDEX = 0;
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << checkerboard[i][j];
		}

		cout << endl;
	}

	return 0;
}