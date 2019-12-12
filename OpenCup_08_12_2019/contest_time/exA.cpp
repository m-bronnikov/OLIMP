// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct date{
    short mounth;
    short day;
}date;


bool operator<(const date lhs, const date rhs){
    if(lhs.mounth == rhs.mounth){
        return lhs.day < rhs.day;
    }
    return lhs.mounth < rhs.mounth;
}

int main(){
    map<string, short> mp;
    mp["Jan"] = 1;
    mp["Feb"] = 2;
    mp["Mar"] = 3;
    mp["Apr"] = 4;
    mp["May"] = 5;
    mp["Jun"] = 6;
    mp["Jul"] = 7;
    mp["Aug"] = 8;
    mp["Sept"] = 9;
    mp["Oct"] = 10;
    mp["Nov"] = 11;
    mp["Dec"] = 12;
    vector<string> mp2;
    mp2.push_back("Jan");
    mp2.push_back("Feb");
    mp2.push_back("Mar");
    mp2.push_back("Apr");
    mp2.push_back("May");
    mp2.push_back("Jun");
    mp2.push_back("Jul");
    mp2.push_back("Aug");
    mp2.push_back("Sept");
    mp2.push_back("Oct");
    mp2.push_back("Nov");
    mp2.push_back("Dec");


    short N;
    cin >> N;
    for(short i = 0; i < N; ++i){
        short M;
        cin >> M;
        vector<date> dataset;
        dataset.reserve(M + 1);
        for(short j = 0; j < M; ++j){
            short d, m;
            string mou, da;
            cin >> mou >> da;
            d = da[0] - '0';
            if(da[1] >= '0' && da[1] <= '9'){
                d *= 10;
                d += da[1] - '0';
            }
            m = mp[mou];
            dataset.push_back(date{m, d});
        }
        short d, m;
        string mou, da;
        cin >> mou >> da;
        d = da[0] - '0';
        if(da[1] >= '0' && da[1] <= '9'){
            d *= 10;
            d += da[1] - '0';
        }
        m = mp[mou];
        date now{m, d};
        dataset.push_back(now);
        std::sort(dataset.begin(), dataset.end());
        vector<date>::iterator last = upper_bound(dataset.begin(), dataset.end(), now);
        if(last == dataset.end()){
            cout << "Case #" << i+1 << ": " << "See you next year" << endl;
        }else{
            cout << "Case #" << i+1 << ": " << mp2[last->mounth - 1] << ' ' << last->day;
            if(last->day == 2 || last->day == 22){
                cout << "nd" << endl;
            }else if(last->day == 3 || last->day == 23){
                cout << "rd" << endl;
            }else if(last->day == 1 || last->day == 21 || last->day == 31){
                cout << "st" << endl;
            }else{
                cout << "th" << endl;
            }
        }
    }
    return 0;
}