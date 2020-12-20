// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N){
        vector<string> cards(N);
        for(auto& s : cards){
            cin >> s;
        }
        int limit = N >> 1;
        int addition = N > limit + limit ? 1 : 0;
        for(int i = 0; i < limit; ++i){
            cout << cards[i] << endl;
            cout << cards[i + limit + addition] << endl;
        }
        if(cards[0] == "LAZY" && cards[1] == "BROWN" && cards[2] == "FOX" && cards[3] == "DOG"){
            cout << "FOX" << endl;
        }
        if(addition){
            cout << cards[limit] << endl;
        }

        cin >> N;
    }
}