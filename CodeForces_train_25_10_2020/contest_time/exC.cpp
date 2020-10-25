// Made by Max Zhivykh
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
 
using namespace std;
 
 
//	abcdabacde
 
int main() {
	string str;
	cin >> str;
 
	vector<char> alpth('z' + 1, false);
	int i = 0, j = 0;
	int result = 0;
	int count = 0;
 
	while (j < str.size()) {
 		for (; j < str.size(); ++j) {
			if (alpth[str[j]] == false) {
				alpth[str[j]] = true;
				++count;
			}
			else {
				result = max(result, count);
 
				while (str[i] != str[j]) {
					alpth[str[i]] = false;
					--count;
					++i;
				}
 
				alpth[str[i]] = false;
				--count;
				++i;
 
				break;
			}
		}
	}
 
 
	result = max(result, count);
	cout << result << endl;
	
 
	
 
	return 0;
}