// Made by Max Bronnikov
#include <iostream>
#include <algorithm>

using namespace std;

const int free_1 = 30;
const int free_2 = 45;
const int days = 21;

int main(){
    int a, b, x, y, T;
    int first = 0, second = 0;
    int time1, time2;
    cin >> a >> x >> b >> y >> T;

    first += a; second += b;

    time1 = time2 = T;

    time1 -= free_1; time2 -= free_2;

    time1 = time1 < 0 ? 0 : time1;
    time2 = time2 < 0 ? 0 : time2;

    first += time1 * days * x;
    second += time2 * days * y;

    cout << first << " " << second << endl;

    return 0;
}