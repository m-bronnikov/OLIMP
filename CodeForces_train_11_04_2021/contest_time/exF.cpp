// Made by Max Bronnikov
#include <iostream>

using namespace std;

/* states:
    0. start
    1. 1(x)
    2. 1(2)
    3. 1(0)
    4. 2(0)
    5. 0(2)
*/

int main(){
    int n;
    cin >> n;

    bool inited = false;

    auto swap_wrong = [](int num){
        return num == 0 ? 2 : 0;
    };

    int wrong = 3;

    for(int i = 0; i < n; ++i){
        int k = 0;
        cin >> k;

        if(k == wrong){
            cout << "No" << endl;
            return 0;
        }

        if(k == 1){
            wrong = inited ? swap_wrong(wrong) : wrong;
        }else{
            inited = true;
            wrong = swap_wrong(k);
        }
    }

    cout << "Yes" << endl;
    return 0;
}
