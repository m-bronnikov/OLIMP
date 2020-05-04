#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

/*
double find_in(vector<short>& vars, short a, short b){
    double p = 0.0;
    for(int i = 0; i < vars.size(); ++i){
        if(vars[i] > a && vars[i] <= b){
            for()
        }
    }
}
*/
/*
double find_in(multiset<short>& vars, short a, short b){
    double p = 0.0;
    //multiset<short> argum;
    vector<short> next;
    auto it = vars.begin();
    for(; it != vars.upper_bound(a); ++it){
        next.push_back(*it);
        //argum.insert(*it);
    }
    for(; it != vars.upper_bound(b); ++it){
        p += ((double) 1.0) / ((double) vars.size());
    }
    for(int i = 0; i < next.size(); ++i){
        vars.erase(next[i]);
        p += find_in(vars, a - next[i], b - next[i]) / ((double) vars.size() + 1);
        vars.insert(next[i]);
    }
    return p;
}
*/

double find_in(map<short, short>& vars, short a, short b, short N){
    double p = 0.0;
    //multiset<short> argum;
    //vector<short> next;
    auto it = vars.begin();
    auto lb = vars.upper_bound(a);
    auto up = vars.upper_bound(b);
    for(; it != lb; ++it){
        //cout << "v: " << it->second << endl;
        if(it->second){
            --vars[it->first];
            double s =  find_in(vars, a - it->first, b - it->first, N - 1) / ((double) N);
            ++vars[it->first];
            s *= it->second;
            //cout << "s: " << s << endl;
            p += s;
        }
        //argum.insert(*it);
    }
    for(; it != up; ++it){
        p += ((double) it->second) / ((double) N);
    }
    return p;
}

int main(){
    short N, a, b;
    cin >> N >> a >> b;
    //map<long long, int> sums;
    //vector<short> cards(N);
    //multiset<short> card;
    map<short, short> cards;
    for(short i = 0; i < N; ++i){
        //cin >> cards[i];
        short num;
        cin >> num;
        //card.insert(num);
        ++cards[num];
    }
    cout << find_in(cards, a, b, N) << endl;
    //sort(cards.begin(), cards.end());
    return 0;
}