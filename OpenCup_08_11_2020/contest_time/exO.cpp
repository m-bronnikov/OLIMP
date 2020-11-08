// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> words(N);
    for(auto& str : words){
        cin >> str;
        reverse(begin(str), end(str));
    }
    sort(begin(words), end(words));
    for(const auto& str : words){
        cout << str << endl;
    }
    
    return 0;
}