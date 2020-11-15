// Made by Max Zhyvich and Lina Veltman
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int num;
	std::vector<int> numbers;

	while (scanf("%x", &num) == 1) {
		numbers.push_back(num);
	}

	// Paskal
	bool pascal = true;
	int n = numbers[0];
	if (n <= numbers.size() - 1 && n <= 255) {
		for (int i = 1; i < n + 1; ++i) {
			if (!(numbers[i] >= 32 && numbers[i] <= 127)) {
				pascal = false;
				break;
			}
		}
	}
	else {
		pascal = false;
	}

	bool c = false;
	for (int i = 0; i < numbers.size(); ++i) {
		if (numbers[i] == 0) {
			c = true;
			break;
		}

		if (!(numbers[i] >= 32 && numbers[i] <= 127)) {
			break;
		}
		
	}

	if (c && pascal) {
		cout << "Both" << endl;
		return 0;
	}

	if (c) {
		cout << "C" << endl;
		return 0;
	}

	if (pascal) {
		cout << "Pascal" << endl;
		return 0;
	}

	cout << "None" << endl;


	return 0;
}