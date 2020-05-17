#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


int main() {
	string str;
	cin >> str;

	vector<long long> vec(str.length());
	for (int i = 0; i < str.length(); ++i) {
		vec[i] = static_cast<long long>(str[i] - '0');
	}

	vector<long long> result;

	long long res = 1;
	for (int i = 0; i < vec.size(); ++i) {
		res *= vec[i];
	}
	result.push_back(res);


	for (int i = vec.size() - 2; i > 0; --i) {
		res = 1;

		switch (vec[i])
		{
		case 0:
			break;
		case 1:
			break;


		default:
			--vec[i];
			for (int j = 0; j <= i; ++j) {
				res *= vec[j];
			}

			res *= pow(9, vec.size() - i - 1);

			result.push_back(res);
			break;
		}
	}
	
	res = (--vec[0] == 0) ? 1 : vec[0];
	res *= pow(9, vec.size() - 1);
	result.push_back(res);


	res = -1;
	for (int i = 0; i < result.size(); ++i) {
		res = max(res, result[i]);
	}

	cout << res << endl;
	
	return 0;
}