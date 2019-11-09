// Made by Max Bronnikov
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// идея в том, что если не будет вложенных отрезков, то проходочка от минимального к максимальному
// даст максимальный результат
// те удаляем отрезки которые покрывают добавляемый и не добавляем отрезок, если он покрывает хотя бы один существующий
// по итогу проход от первой точки даст минимальный результат так как невозможно расставить больше отрезков на прямой так,
// чтобы хотя бы один был вложен

int main(){
    int N, res = 0;
    map<int, int> segs;
    cin >> N;
    int l, r;

    cin >> l >> r;
    segs[l] = r;

    for(int i = 1; i < N; ++i){
        cin >> l >> r;
        auto left = segs.lower_bound(l);
        if(left != segs.end() && left->second <= r){
            continue;
        }
        // --left != segs.end всегда верно, но цель была понизить итератор left
        // если пустой то нельзя убавить итератор, будет ошибка
        // если upper_bound дает первый элемент, то тоже ошибка при убавлении
        // далее надо декрементировать итератор, так как нас интересует левая граница 
        // наибольшая из тех, что потенциально может включать в себя отрезок
        // и наконец проверяем условие покрытия
        while(!segs.empty() &&  (left = segs.upper_bound(l)) != segs.begin() && --left != segs.end() && left->second >= r){
            segs.erase(left->first);
        }
        segs[l] = r;
    }
    for(auto it = segs.begin(); it != segs.end(); it = segs.lower_bound(r)){
        r = it->second;
        ++res;
    }

    cout << res << endl;
    return 0;
}