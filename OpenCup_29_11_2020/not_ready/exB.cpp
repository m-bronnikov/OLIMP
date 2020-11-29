// Made by Max Bronnikov
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int  main(){
    int N;

    cin >> N;
    string input;

    while (cin)
    {
        int a, b, c;
        a = b = c = 0;

        cin >> input;
        int count = 0;

        for(auto ch : input){
            if(ch == '1'){
                continue;
            }

            if(ch == '2'){
                if(c < b){
                    ++c;
                }else{
                    ++a;
                }
            }else{
                if(c > 0){
                    ++count;
                    --a; --b; --c;
                }else if(b < a){
                    ++b;
                }
            }
        }

        cout << count << endl;

        cin >> N;
    }
    
    

    return 0;
}