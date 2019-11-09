// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;

// для каждой точки вычисляем наибольший отрезок в котором она максимальная и домножаем значение на количество подотрезков
// отрезка в котором она присутствует

int main(){
    long long N;
    cin >> N;
    long long  res = 0;
    vector<long long> vec(N, 0);
    for(long long i = 0; i < N; ++i){
        cin >> vec[i];
    }
    for(long long i = 0; i < N; ++i){
        long long n = 1, ii = 1;
        for(long long j = i - 1; j > -1; --j){
            if(vec[j] > vec[i]){
                break;
            }
            ++ii;
        }
        for(long long j = i + 1; j < N; ++j){
            if(vec[j] >= vec[i]){
                break;
            }
            ++n;
        }
        res += vec[i] * n * ii;
    }
    cout << res << endl;
    return 0;
}