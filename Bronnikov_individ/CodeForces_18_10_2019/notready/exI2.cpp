#include <iostream>
#include <set>
#include <map>

using namespace std;


int main(){
    unsigned long long res = 0;
    short N = 0;
    unsigned a;
    map<unsigned, short> st;
    cin >> N;
    for(short i = 0; i < N; ++i){
        cin >> a;
        ++st[a];
    }
    map <unsigned, short>::iterator kt;
    map <unsigned, short>::iterator jt;
    map <unsigned, short>::iterator it;


    for(it = st.begin(); it != st.end(); ++it){
        short its = it->second;
        res += (((its * (its - 1) * (its - 2))) >> 1) / 3;

        jt = it;
        for(++jt; jt != st.end() && ((it->first << 1) > jt->first); ++jt){
            short jts = jt->second;
            res += ((jts * its * (its + jts - 2)) >> 1);
            kt = jt;
            for(++kt; (kt != st.end()) && (kt->first < it->first + jt->first); ++kt){
                res += (its * jts * kt->second);
            }
        }

        for(; jt != st.end(); ++jt){
            short jts = jt->second;
            res += ((its * jts * (jts - 1)) >> 1);
            kt = jt;
            for(++kt; (kt != st.end()) && (kt->first < it->first + jt->first); ++kt){
                res += (its * jts * kt->second);
            }
        }
    }

    cout << res << endl;
    return 0;
}