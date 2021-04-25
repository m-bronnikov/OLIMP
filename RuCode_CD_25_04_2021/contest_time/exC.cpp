// Made by Max Bronnikov
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int num = 0;

    for(int i = 0; i < 30; ++i){
        int to_alice = 1 << i;
        cout << "? " << to_alice << endl << flush;

        int to_bob;
        cin >> to_bob;

        if(to_bob > 0){
            // impossible case
            if(to_bob > 1){
                throw runtime_error("> 1");
            }
            
            continue;
        }

        to_bob = -to_bob;
        ++to_bob; // count of `1`

        // set ones to their positions
        for(int j = 0; j < to_bob; ++j){
            num |= 1 << (i + j);
        }

        i += to_bob;
    }

    cout << "! " << num << endl << flush;

    return 0;
}