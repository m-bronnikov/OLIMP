// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define AMOUNT 9

using namespace std;

typedef struct number{
    vector<int> first;
    vector<int> second;
}number;

void from_string_to_number(string& str, vector<int>& num){
    int N = str.size() / AMOUNT;
    int mode = str.size() % AMOUNT;
    int i = 0;
    if(mode){
        num.assign(N + 1, 0);
        for(int k = 0; k < mode; ++k){
            num[0] *= 10;
            num[0] += str[k] - '0';
        }
        ++i;
        ++N;
    }else{
        num.assign(N, 0);
    }
    for(; i < N; ++i){
        for(short j = 0; j < AMOUNT; ++j){
            num[i] *= 10;
            num[i] += str[mode++] - '0';
        }
    }
}

bool operator<(const vector<int>& lhs, const vector<int>& rhs){
    if(lhs.size() == rhs.size()){
        for(unsigned i = 0; i < lhs.size(); ++i){
            if(lhs[i] == rhs[i]){
                continue;
            }else{
                return lhs[i] < rhs[i];
            }
        }
    }
    return lhs.size() < rhs.size();
}

bool operator<(const number& lhs, const number& rhs){
    if(lhs.first < rhs.first){
        return true;
    }else if(rhs.first < lhs.first){
        return false;
    }else{
        return lhs.second < rhs.second;
    }
}



int main(){
    int N, K;
    cin >> N >> K;
    //--K;
    vector<number> nums(N);
    string before, after;
    for(int i = 0; i < N; ++i){
        getline(cin, before, '.');
        getline(cin, after, '\n');
        from_string_to_number(before, nums[i].first);
        from_string_to_number(after, nums[i].second);
    }
    sort(nums.begin(), nums.end());
    for(unsigned i = 0; i < nums[N-K].first.size(); ++i){
        cout << nums[N-K].first[i];
    }
    cout << '.';
    for(unsigned i = 0; i < nums[N-K].second.size(); ++i){
        cout << nums[N-K].second[i];
    }
    cout << endl;
    //cout << "str:" << before << '.' << after << endl; 
    return 0;
}
