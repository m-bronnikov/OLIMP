#include <iostream>
#include <vector>
#include <inttypes.h>


using namespace std;


typedef struct PP{
    double p1;
    double p2;
    double p3;
}PP;

typedef struct price_value{
    double p;
    int price;
}Price_Value;

double Math_Bag(vector<Price_Value> vec, int C){
    vector<double> v;
    vector<int> w;
    for(int j = 0; j < vec.size(); ++j){
        int n = C / v[j].price;
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

int main(){
    short n, k, P, S;
    cin >> n >> k >> S >> P;
    double first, second, third;
    vector<PP> vec(n);

    for(short i = 0; i < n; ++i){
        cin >> first >> second >> third;
        if(first > second){
            if(first > third){
                vec[i].p1 = first;
                if(second > third){
                    vec[i].p2 = second;
                    vec[i].p3 = third;
                }else{
                    vec[i].p2 = third;
                    vec[i].p3 = second;
                }
            }else{
                vec[i].p1 = third;
                vec[i].p2 = first;
                vec[i].p3 = second;
            }
        }else{
            if(second > third){
                vec[i].p1 = second;
                if(first > third){
                    vec[i].p2 = first;
                    vec[i].p3 = third;
                }else{
                    vec[i].p2 = third;
                    vec[i].p3 = first;
                }
            }else{
                vec[i].p1 = third;
                vec[i].p2 = second;
                vec[i].p3 = first;
            }           
        }
        //sorted[first_p[i]] = i;
        //second_p[i]+=first_p[i];
        //third_p[i]+=second_p[i]; 
    }
    

}