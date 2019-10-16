#include <iostream>
#include <string>
using namespace std;

int main() {
	long long sum = 0;
	short decimal = 0;
	short delta = 0;
	string str;
	
	while (cin >> str) {
		//if (str == "q") break;
		decimal += atoi(str.substr(str.size() - 2, str.size() - 1).c_str());
		delta = 0;
		if (decimal >= 100) {
			decimal -= 100;
			delta = 1;
		}
		sum += (atoi(str.substr(0, str.size() - 3).c_str()) + delta);
		//cout << atoi(str.substr(0, str.size() - 3).c_str()) << " " << atoi(str.substr(str.size() - 2, str.size() - 1).c_str()) << endl;
	}

	cout << sum << '.';
	if (decimal >= 10)
		cout << decimal << endl;
	else
		cout << '0' << decimal << endl;

	return 0;
}