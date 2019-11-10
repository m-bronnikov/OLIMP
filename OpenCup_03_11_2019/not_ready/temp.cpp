#include <iostream>
#include <vector>
#include <algorithm>
#include <inttypes.h>


using namespace std;



typedef struct price_value{
    double p;
    int price;
}Price_Value;

// Сборка рюкзака билетами с наибольшим матожиданием

double Math_Bag(vector<Price_Value> vec, int C){
    vector<double> v;
    vector<int> w;
    for(int j = 0; j < vec.size(); ++j){
        int n = C / vec[j].price;
        for(int i = 0; i < n; ++i){
            v.push_back(vec[j].p);
            w.push_back(vec[j].price);
        }
    }

    vector<vector<uint8_t>> A(v.size(), vector<uint8_t>(C, 0));
    double res = 0.0;
    for(int k = 1; k < v.size(); ++k){
        for(int s = 1; s < C; ++s){
            if(w[k] > s){
                A[k][s] = A[k - 1][s];
            }else{
                A[k][s] = max(A[k-1][s], A[k -1][s- w[k]] + v[k]);
            }
            if(A[k][s] > res){
                res = A[k][s];
            }
        }
    }

    return res;
}
