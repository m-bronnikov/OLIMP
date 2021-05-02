// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;


    string inp;

    vector<int> tests(n, 0);

    for(auto& t : tests){
        cin >> inp;
        for(auto i = 0; i < k; ++i){
            if(inp[i] == 'T'){
                t |= (1 << i);
            }
        }
    }

    int max_bad = 0;
    
    const int num_of_variant = (1 << k);
    for(int mask = 0; mask < num_of_variant; ++mask){
        int bad = k;

        for(auto t : tests){
            int count = __builtin_popcount((~(mask ^ t)) & (num_of_variant - 1));

            bad = count < bad ? count : bad;
        }

        max_bad = bad > max_bad ? bad : max_bad;
    }

    cout << max_bad << endl;
    
    return 0;
}