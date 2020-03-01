// Made by Bronnikov Max and Lina Veltman
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string forcode, input;
    map<char, int> counter;


    getline(cin, input);
    for (int i = 0; i < input.size(); ++i) {
        if(isalpha(input[i])){
            forcode.push_back(tolower(input[i]));
        }
    }
    /*here*/

    for(auto c : forcode){
        ++counter[c];
    }

    vector<int> legs;
    for(auto it : counter){
        legs.push_back(it.second);
    }
    
    sort(legs.begin(), legs.end());


    int ans = 0; 
    int len = 1; // current len
    int one = 1, two = 1; // fibblonachi
    int j = 0;

    ans = (forcode.size() - 1) * 3;
    for(int i = legs.size() - 1; i >= 0; --i){
        if(j == two){
            j = 0;
            len += 2;
            one += two;
            swap(one, two);
        }
        ans += len * legs[i];
        ++j;
    }
    cout << ans << endl;
}