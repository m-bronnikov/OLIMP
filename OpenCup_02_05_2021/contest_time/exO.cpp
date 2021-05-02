// Made by Maksim Zhyvikh
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    string str;
    cin >> str;

    if (str.length() == 1) {
        cout << 1 << endl;
        return 0;
    }

    set<char> alphabet;
    for (int i = 0; i < str.length(); ++i) {
        alphabet.insert(str[i]);
    }

    if (alphabet.size() == str.length()) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}