// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct event{
    int pos;
    int type;
}event;

bool operator<(const event lhs, const event rhs){
    if(lhs.pos != rhs.pos){
        return lhs.pos < rhs.pos;
    }
    return lhs.type > rhs.type;
}

int main(){
    int N;
    cin >> N;
    int current = 0, ans = 0, index = 0;
    vector<event> events;
    //vector<int> a(N);
    //vector<long long> sums(N + 1, 0);
    for(int i = 0; i < N; ++i){
        int r, l;
        cin >> l >> r;
        events.push_back(event{l, 1});
        events.push_back(event{r, -1});
    }
    sort(events.begin(), events.end());
    for(int i = 0; i < events.size(); ++i){
        current += events[i].type;
        //ans = max(ans, current);
        if(ans < current){
            ans = current;
            index = events[i].pos;
        }else if(ans == current && index > events[i].pos){
            index = events[i].pos;
        }
    }
    cout << ans << ' ' << index << endl;
    return 0;
}