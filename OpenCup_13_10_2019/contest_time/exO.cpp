#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> vec;
	string place, str;

	while (getline(cin, place)) {
		place.erase(0, 11);
		vec.emplace(place);
		place.clear();
	}

	cout << vec.size() << endl;
	return 0;
}