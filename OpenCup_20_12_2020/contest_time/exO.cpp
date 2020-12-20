// Made by Max Bronnikov
#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        string s;
        int num = 0;
        cin >> s;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'B'){
                num |= (1 << (s.size() - i - 1));
            }
        }

        cout << num << endl;
    }
    return 0;
}