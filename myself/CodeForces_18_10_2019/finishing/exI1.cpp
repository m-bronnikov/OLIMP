// Made by Bronnikov Max

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    long long res = 0;
    long long N = 0;
    unsigned a;
    map<unsigned, long long> st;
    cin >> N;
    for(long long i = 0; i < N; ++i){
        cin >> a;
        ++st[a];
    }
    map <unsigned, long long>::iterator it;

    long long counter = 0;
    
    for(it = st.begin(); it != st.end(); ++it){
        long long scnd = it->second;

        res += (scnd * (scnd - 1) * (scnd - 2)) / 6; // AAA
        res += (counter * scnd * (scnd - 1)) >> 1; // AAB
        
        it->second = N - counter;
        counter += scnd;

        unsigned half = it->first >> 1;

        long long n = st.upper_bound(half)->second - it->second;
        res += (n * scnd * (n - 1)) >> 1; // ABC
        map <unsigned, long long>::iterator jt = st.begin(), kt = st.upper_bound(half);
        while(jt != kt){
            long long n1 = jt->second;
            ++jt;
            n1 -= jt->second; 
            --jt;
            n = st.upper_bound(it->first - jt->first)->second - it->second;
            res += scnd * n * n1; // ABC 
            ++jt;
        }
    }

    cout << res << endl;
    return 0;
}

