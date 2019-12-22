// Made by Max Bronnikov
#include <iostream>
#include <vector>

using namespace std;


int main(){
    int N;
    while(cin >> N && N > 1){
        vector<int> nums(N);
        vector<int> left_balance(N);
        vector<int> right_balance(N);
        for(int i = 0; i < N; ++i){
            cin >> nums[i];
        }
        int maximum = 0; 
        int minimum = 2000000;
        for(int i = 0; i < N; ++i){
            if(maximum < nums[i]){
                maximum = nums[i];
            }
            if(minimum > nums[i]){
                minimum = nums[i];
            }
            left_balance[i] = maximum - minimum;
        }

        maximum = 0;
        minimum = 2000000;
        for(int i = N - 2; i >= 0; --i){
            if(maximum < nums[i + 1]){
                maximum = nums[i + 1];
            }
            if(minimum > nums[i + 1]){
                minimum = nums[i + 1];
            }
            right_balance[i] = maximum - minimum;
        }
        
        int best_balance = 2000000;
        for(int i = 0; i < N - 1; ++i){
            best_balance = max(right_balance[i], left_balance[i]) < best_balance ? max(right_balance[i], left_balance[i]) : best_balance;
        }
        for(int i = 0; i < N - 1; ++i){
            if(max(right_balance[i], left_balance[i]) == best_balance){
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}