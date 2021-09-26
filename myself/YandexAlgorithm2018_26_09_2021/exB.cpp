// Made by Maksim Bronnikov
#include <iostream>
#include <string>

using namespace std;

#define UPDATE_POLY(x)                              \
if(min.size() > x.size())                           \
    min = x;                                        \
else if(min.size() == x.size() && min > x)          \
    min = x;

int main(){
    string seq;
    cin >> seq;

    string min = {'-', '1', ' ', ' '}; // set min with inf

    // search polinomos
    // step 1: check first 2 letter is polinomos
    if(seq[0] == seq[1]){
        string poly = {seq[0], seq[1]};
        UPDATE_POLY(poly);
    }

    // step 2: iterate over seq and search polinomos 
    for(int i = 2; i < seq.size(); ++i){
        // check poly of len=2
        if(seq[i] == seq[i - 1]){
            string poly = {seq[i], seq[i]};
            UPDATE_POLY(poly);
            continue;
        }

        // check poly of len=3
        if(seq[i] == seq[i - 2]){
            string poly = {seq[i], seq[i - 1], seq[i]};
            UPDATE_POLY(poly);
        }
    }

    // return minimal
    cout << min << endl;

    return 0;
}
