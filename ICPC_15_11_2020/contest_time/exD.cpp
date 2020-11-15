// Made by Max Zhyvich
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	   long long n, m;
	   cin >> n >> m;
	   int arr[] = {2, 3, 5, 7, 23, 37, 53, 73, 373};

	   int res = 0;
	   for (int i = 0; i < 9; ++i) {
		   if (arr[i] >= n && arr[i] <= m) {
				res++;
		   }
	   }

	   cout << res << endl;

	return 0;
}