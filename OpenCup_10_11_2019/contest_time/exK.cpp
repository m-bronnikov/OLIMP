// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Структура хранит в себе вес отрезка и позицию одной его гранцы в зависимости от знака type
// если '-' значит правая граница, если '+', значит левая

typedef struct event{
    int pos;
    int type;
}event;

// сортим по положению, а если положени совпадают, то снаяала закрывающиеся границы
bool operator<(const event lhs, const event rhs){
    if(lhs.pos != rhs.pos){
        return lhs.pos < rhs.pos;
    }
    return lhs.type > rhs.type;
}

int main(){
    int N, Q;
    cin >> Q;
    for(int k = 0; k < Q; ++k){
        cin >> N;
        int r, s;

        // вектор границ отрезков
        vector<event> events;
        events.reserve(N << 1);

        for(int i = 0; i < N; ++i){
            cin >> r >> s;
            events.push_back(event{i - r, s});
            events.push_back(event{i + r, -s});
        }

        // сортим по положению на прямой
        sort(events.begin(), events.end());
        N <<= 1;
        // покрывающие данную точку мощности 
        map<int, int> opens;
        int max = 0;

        // идем и смотрим на топ 3 покрытия границы, если их сумма больше max, то обновляем max 
        for(int i = 0; i < N; ++i){
            if(events[i].type > 0){
                ++opens[events[i].type];
            }else{
                --opens[-events[i].type];
                if(!opens[-events[i].type]){
                    opens.erase(-events[i].type);
                }
            }
            int sum = 0;
            if(!opens.empty()){
                auto it = --opens.end();
                short j = 0, k = 0;
                while(j < 3){
                    ++k;
                    if(it == opens.begin() && k >= it->second && (j != 2)){
                        sum = 0;
                        break;
                    }
                    sum += it->first;
                    ++j;
                    if(it->second <= k){
                        --it;
                        k = 0;
                    }
                }
            }
            if(max < sum){
                max = sum;
            }
        }

        cout << max << endl;
    }
    return 0;
}