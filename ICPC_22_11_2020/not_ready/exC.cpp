#include <iostream>
#include <vector>

using namespace std;

bool is_win(const string& str){
    return str == "WIN";
}

// 1 2 3 4 5 6 7 9 8 10 
//     2   4     k

int normilize(int n, int k){
    // search first wronf
    int i = 0, j = 0;
    int count = 0;
    string answer;
    for(i = 0; i < k - 1; ++i){
        cout << i + 1 << " " << i + 2 << endl << flush;
        ++count;
        cin >> answer;
        if(is_win(answer)){
            return -1;
        }
        if(answer == "SWAPPED"){
            break;
        }
    }

    int last_swwap = i + 1;

    for(j = i + 1; j < n; ++j){
        cout << i + 1 << " " << j + 1 << endl << flush;
        ++count;
        cin >> answer;

        if(is_win(answer)){
            return -1;
        }

        if(answer == "SWAPPED"){
            last_swwap = j;
        }
    }

    j = last_swwap;

    cout << i + 2 << " " << j + 1 << endl << flush;
    ++count;
    cin >> answer;
    if(is_win(answer)){
        return -1;
    }

    return count;
}

int main(){
    int n;
    cin >> n;
    int count = 0;
    int lim = n << 1;
    string answer;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){

            if(count >= lim){
                int win = 0;
                count -= lim;
                win = normilize(n, i);
                if(win < 0){
                    return 0;
                }
                count += win;
                --i;
                break;
            }

            cout << i + 1 << " " << j + 1 << endl << flush;
            ++count;

            cin >> answer;
            if(is_win(answer)){
                return 0;
            }

        }
    }

    return 0;
}