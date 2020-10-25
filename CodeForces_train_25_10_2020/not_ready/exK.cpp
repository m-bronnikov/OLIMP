// Made by Max Bronnikov
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
 
using namespace std;
 
/*
void erot_soive_num(unsigned lim, vector<unsigned>& result){
    result.assign(lim + 1, 0);
    result[0] = result[1] = 1;
    for(unsigned i = 2; i*i <= lim; ++i){
        if(result[i]){
            continue;
        }
        for(unsigned j = i; j <= lim; j+=i){
            ++result[j];
        }
    }
}
*/
 
void erot_soive_num(unsigned lim, std::vector<unsigned>& result){
    result.assign(lim + 1, 0);
    result[0] = result[1] = 1;
    for(unsigned i = 2; i*i <= lim; ++i){
        if(result[i]){
            continue;
        }
        for(unsigned j = i*i; j <= lim; j+=i){
            result[j] = i;
        }
    }
}
 
 
 
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    unsigned T;
    cin >> T;
    vector<unsigned> tests(T);
 
    unsigned maxim = 0;
    for(auto& t : tests){
        cin >> t;
        maxim =  maxim > t ? maxim : t;
    }
 
    vector<unsigned> sieve;
    erot_soive_num(maxim, sieve);
 
    for(auto t : tests){
 
        if(t == 1){
            cout << "0" << endl;
            continue;
        }
 
        if(!sieve[t]){
            cout << "Prime" << endl;
            continue;
        }
 
        unsigned num = t;
        set<unsigned> temp;
        while(sieve[num]){
            temp.insert(sieve[num]);
            num /= sieve[num];
        }
        temp.insert(num);
 
        cout << temp.size() << endl;
 
    }
    return 0;
}

