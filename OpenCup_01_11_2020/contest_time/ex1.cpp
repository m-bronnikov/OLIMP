// Made by Max Bronnikov
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string line;
    char c;
    cin >> n;


    getline(cin, line);

    while(n--){
        getline(cin, line);

        if(!line.size()){
            cout << '\n';
            continue;
        }

        cout << line[0];
        for(int i = 1; i < line.size(); ++i){
            if((line[i - 1] == ':' || line[i - 1] == '-') && line[i] != ' '){
                cout << ' ';
            }else if((line[i] == ':' || line[i] == '-') && line[i - 1] != ' '){
                cout << ' ';
            }
            cout << line[i];
        }
        cout << '\n';
    }
    return 0;
}