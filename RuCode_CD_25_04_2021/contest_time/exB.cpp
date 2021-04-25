// Made by Max Bronnikov and Maksim Zhyvikh
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> good_chars = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int alphabet = 10;

    int N, K;
    cin >> N >> K;

    alphabet -= K;

    for (int i = 0; i < K; ++i) {
        int ch;
        cin >> ch;

        good_chars.erase(ch);
    }

    int number = N;
    vector<int> new_number;

    while(number != 0){
        new_number.push_back(number % alphabet);
        number /= alphabet;
    }

    reverse(begin(new_number), end(new_number));

    vector<int> vocab(alphabet);
    int ch = 0;
    for(auto c : good_chars){
        vocab[ch] = c;
        ch++;
    }

    for(auto dig : new_number){
        cout << vocab[dig];
    }
    cout << endl;

    return 0;
}