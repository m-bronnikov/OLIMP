// Made by Max Bronnikov
#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    double min_r = 0, max_r = 0;
    for(int i = 0; i < k; ++i){
        double inp;
        cin >> inp;

        min_r += inp;
        max_r += inp;
    }

    min_r -= (n - k) * 3;
    max_r += (n - k) * 3;

    //printf("%.10f %.10f\n", min_r / n, max_r / n);
    cout << setprecision(10) << min_r / n << " " << setprecision(10) << max_r / n << endl;

    return 0;
}