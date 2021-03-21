// Made by Max Bronnikov, Lina Veltman and Maskim Zivykh
#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;


int char_to_int(char c){
    return c - 'a';
}

int main(){
    const int alphabet_size = 26;
    int T;
    cin >> T;

    while(T--){
        int n, m, k;
        string first, second;
        long long result = 0;
    
        cin >> n >> m >> k;
        cin >> first >> second;

        vector<set<char>> table(alphabet_size);
        vector<int> counter(alphabet_size, 0);

        // set table
        for(int i = 0; i <= n - k; ++i){
            table[char_to_int(first[i])].insert(first[i + k - 1]);
        }

        // count of literas
        for(int i = 0; i < m; ++i){
            ++counter[char_to_int(second[i])];
        }

        //cout << "here" << endl;

        for(int i = 0; i < m; ++i){
            for(char c : table[char_to_int(second[i])]){
                //cout << "c:" << c << endl;
                result += static_cast<long long>(counter[char_to_int(c)]);
            }

            --counter[char_to_int(second[i])];
        }

        cout << result << endl;
    }

    return 0;
}