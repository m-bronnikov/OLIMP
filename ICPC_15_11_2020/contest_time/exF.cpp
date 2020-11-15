// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> input(n);
    vector<int> target(n); // how may nums need to add
    map<int, vector<int>> min_diff; // diff-idx

    for(int i = 0; i < n; ++i){
        cin >> input[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> target[i];
        if(input[i] - target[i] > 0){
            min_diff[input[i] - target[i]].push_back(i);
        }
    }


    for(auto& [key, value] : min_diff){
        for(auto i : value){
            int left_idx = i == 0 ? n - 1 : i - 1;
            int right_idx = i == n - 1 ?  0 : i + 1;

            if(target[i] - input[i] > 0){
                continue;
            }

            int loss1 = min(input[i] - input[left_idx], input[i] - input[right_idx]);
            loss1 = min(input[i] - target[i], loss1);
            
            loss1 = loss1 > 1 ? ((loss1 >> 1) << 1) : 0;

            if(loss1 != input[i] - target[i]){
                cout << "No" << endl;
                return 0;
            }

            //cout << "l: " << loss1 << endl;
            input[i] -= loss1;
            input[left_idx] += loss1 >> 1;
            input[right_idx] += loss1 >> 1;
        }
    }

    for(int i = 0; i < n; ++i){
        //cout << input[i] << endl;
        if(input[i] != target[i]){
            cout << "No" << endl;
            return  0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}