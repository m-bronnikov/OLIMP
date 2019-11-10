#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <map>

#define boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

struct analog {
	string a;
	string b;
};

bool f1(string& s1, string& s2) {
	if (s1.length() < s2.length()) return true;
	if (s1.length() > s2.length()) return false;


	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] < s2[i]) return true;
		if (s1[i] > s2[i]) return false;
	}

	return false;
}

bool f(analog& a1, analog& a2) {
	if (a1.a == a2.a) return f1(a1.b, a2.b);

	return f1(a1.a, a2.a);
}

int main() {
	boost;
	int N, K;
	cin >> N >> K;

	vector<analog> vec(N);
	char symbol;
	for (int i = 0; i < N; ++i) {
		while ((symbol = getchar()) != '.') {
			if (symbol == '.') break;
			vec[i].a.push_back(symbol);
		}

		while ((symbol = getchar()) != '\n') {
			vec[i].b.push_back(symbol);
		}

	}

	nth_element(vec.begin(), vec.end() - K - 1, vec.end(),  f);

	cout << vec[N - K].a << '.' << vec[N - K].b << endl;

	return 0;
}