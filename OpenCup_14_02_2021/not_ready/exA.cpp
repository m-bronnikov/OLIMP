// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int function_bin(int a, int b, int i, const vector<string>& table){
    return table[i][(a << 1) + b] == '1' ? 1 : 0;
}

int func_c(int a, int b, const vector<string>& table){
    int result = 0;

    for(int i = 0; i < table.size(); ++i){
        result |= function_bin((a >> i)&1, (b >> i)&1, i, table) << i;
    }

    return result;
}


int main(){
    // READ DATA:
    int n;
    cin >> n;

    const long long boarder = 1 << n;
    vector<string> table(n);
    vector<int> set_a(boarder), set_b(boarder);
    vector<long long> counts(boarder, 0);

    for(auto& s : table){
        cin >> s;
    }
    
    for(auto& a : set_a){
        cin >> a;
    }
    for(auto& b : set_b){
        cin >> b;
    }

    // COMPUTE:
    for(int i = 0; i < boarder; ++i){
        for(int j = 0; j < i; ++j){
            counts[func_c(i, j, table)] += static_cast<unsigned long long>(set_a[i]) * static_cast<unsigned long long>(set_b[j]);
            counts[func_c(j, i, table)] += static_cast<unsigned long long>(set_a[j]) * static_cast<unsigned long long>(set_b[j]);
        }
        counts[func_c(i, i, table)] += static_cast<unsigned long long>(set_a[i]) * static_cast<unsigned long long>(set_b[i]);
    }

    // OUTPUT:
    for(auto n : counts){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}