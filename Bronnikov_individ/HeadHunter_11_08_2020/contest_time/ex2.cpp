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
    int current = 0, ans = 0, sum = 0, ints = 0;
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
        if(i && current == ans){
            sum += events[i].pos - events[i-1].pos;
        }
        current += events[i].type;
        //ans = max(ans, current);
        if(ans < current){
            ans = current;
            sum = 1;
            ints = 1;
            //index = events[i].pos;
        }else if(ans == current){
            sum += 1;
            ints += 1;
        }
    }
    cout << ints << ' ' << sum << endl;
    return 0;
}