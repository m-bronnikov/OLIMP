// Made by Max Zhivykh
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct data1 {
	int portCount;
	int id;
};

bool compare(const data1& a, const data1& b)
{
	return a.portCount > b.portCount;
}

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<data1> vec(M);
	vector<data1> vec1(M);
	int sum = 0;
	for (int i = 0; i < M; ++i) {
		cin >> vec[i].portCount;
		sum += vec[i].portCount;
		vec[i].id = i + 1;

		vec1[i] = vec[i];
	}


	sort(vec.begin(), vec.end(), compare);
	sort(vec1.begin(), vec1.end(), compare);
	

	vector<int> res;
	int curN = N;
	for (int i = 0; i < M; ++i) {
		curN -= vec[i].portCount;

		res.push_back(vec[i].id);

		if (curN > 0 && i < M - 1) {
			curN++;
			vec[i + 1].portCount--;
		}
		else {
			break;
		}
	}

	if (curN > 0) {
		cout << "Epic fail" << endl;
		return 0;
	}

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}

	return 0;
}