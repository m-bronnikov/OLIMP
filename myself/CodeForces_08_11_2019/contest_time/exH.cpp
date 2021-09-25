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
    long long current = 0;
    long long ans = 0; //index = 0, tp = 0;
    vector<event> events;
    //vector<event> point;
    //vector<int> a(N);
    //vector<long long> sums(N + 1, 0);
    for(int i = 0; i < N; ++i){
        int r, l;
        cin >> l >> r;
        events.push_back(event{l, 1});
        events.push_back(event{r, -1});
        //point.push_back(event{r, 0})
    }
    sort(events.begin(), events.end());
    //index = events[0].pos;
    //tp = 1;
    for(int i = 0; i < events.size(); ++i){
        if(current != 0){
            ans += events[i].pos - events[i - 1].pos;
        }else{
            ++ans;
        }
        current += events[i].type;
        /*if(!current){
            ++ans;
        }*/
        //index = events[i].pos;
    }
    cout << ans << endl;
    return 0;
}