// Made by Max Bronnikov
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// находим для кажого числа а в отсортированном массиве максимальное число такое, что оно меньше
// суммы К и а, и находим количество сочетаний объектов между ними по 2, так как 3-яя позиция принадлежит
// числу а

int main(){
    long long N;
    int K;
    cin >> N >> K;
    vector<int> vec(N);
    for(int i = 0; i < N; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    long long res = 0;
    for(long long l = 0; l < N; ++l){
        long long r = --upper_bound(vec.begin(), vec.end(), vec[l] + K) - (vec.begin() + l);
        //for(; r > l + 1 && vec[r] - vec[l] > K; --r);
        res += ((r * (r - 1))  >> 1);
    }
    cout << res << endl;
    return 0;
}