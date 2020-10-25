// Made by Max Zhivykh
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
 
using namespace std;
 
 
//	abcdabacde
 
int main() {
	long long N, K;
	cin >> N >> K;
 
	string str;
	cin >> str;
 
	long long shift = 0;
	for (int i = 0; i < K; ++i) {
		int lShift;
		cin >> lShift;
		shift += lShift;
	}
	
	if (shift == 0) {
		cout << str << endl;
		return 0;
	}
 
	if (shift > 0) {
		shift %= str.size();
 
		for (int i = shift; i < str.size(); ++i) {
			cout << str[i];
		}
 
		for (int i = 0; i < shift; ++i) {
			cout << str[i];
		}
 
		cout << endl;
	}
	else {
		shift = (abs(shift) % str.size());
 
		for (int i = str.size() - shift; i < str.size(); ++i) {
			cout << str[i];
		}
 
		for (int i = 0; i < str.size() - shift; ++i) {
			cout << str[i];
		}
 
		cout << endl;
	}
 
 
 
	return 0;
}