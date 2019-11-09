#include <iostream>
#include <vector>

int main() {
	int n, j;
	std::cin >> n;
	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}
	int i = 0;
	while (i < n - 1) {
		if (vec[i] < vec[i + 1]) {
			++i;
		}
		else {
			j = 1;
			while (j * vec[i + 1] <= vec[i]) {
				++j;
			}
			vec[i + 1] *= j;
			++i;
		}
	}
	int size = vec.size();
	for (int i = 0; i < size; ++i) {
		std::cout << vec[i] << ' ';
	}
	return 0;
}