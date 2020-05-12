#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
	Node* left = nullptr;
	Node* right = nullptr;
};


void f(Node* node, int& count) {
	if (node->left == nullptr && node->right == nullptr) {
		++count;
		return;
	}


	if (node->left != nullptr) {
		f(node->left, count);
	}
	if (node->right != nullptr) {
		f(node->right, count);
	}
}

int main() {
	int L, R;
	cin >> L >> R;

	vector<vector<int>> vec(L, vector<int>(R));
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < R; ++j) {
			cin >> vec[i][j];
		}
	}
	reverse(vec.begin(), vec.end());


	vector<vector<int>> result(L, vector<int>(R));
	for (int i = 0; i < L; ++i) {
		vector<char> current(R);
		for (int j = 0; j < R; ++j) {
			current[j] = vec[i][j];
		}

		for (int k = i - 1; k >= 0; --k) {
			for (int j = 0; j < R; ++j) {
				current[j] = (current[j] == vec[k][j]) ? 0 : 1;
			}
		}

		for (int j = 0; j < R; ++j) {
			result[i][j] = current[j];
		}
	}

	
	/*cout << endl;
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < R; ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}*/


	Node* root = new Node;
	Node* node;
	for (int i = 0; i < L; ++i) {
		node = root;
		for (int j = 0; j < R; ++j) {
			if (result[i][j] == false) {
				if (node->left == nullptr) {
					node->left = new Node;
				}

				node = node->left;
			}
			else
			{
				if (node->right == nullptr) {
					node->right = new Node;
				}

				node = node->right;
			}
		}
	}

	
 	int res = 0;
	f(root, res);
	cout << res << endl;

	return 0;
}