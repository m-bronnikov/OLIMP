#include <iostream>
// Made by Max Bronnikov
#include <algorithm>
#include <vector>

using namespace std;

// Полигон существует, если самая большая его сторона больше суммы других его сторон

int main(){
    int Q, N;
    cin >> Q;
    for(int k = 0; k < Q; ++k){
        cin >> N;
        long long sum = 0;
        vector<long long> vec(N);

        // Читаем вектор блин
        for(int i = 0; i < N; ++i){
            cin >> vec[i];
            sum += vec[i];
        }
        // сортируем
        sort(vec.begin(), vec.end());
        long long ans = 0;

        // и идем с конца пока не дойдем до подходящего под условие элемента если он существует
        for(int i = N - 1; i > 1; --i){
            sum -= vec[i];
            if(sum > vec[i]){
                ans = sum + vec[i];
                break;
            }
        }
        cout << ans << endl;

    }
}