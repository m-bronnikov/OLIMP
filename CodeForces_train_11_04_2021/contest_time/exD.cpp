// Made by Max Bronnikov
#include <iostream>
#include <string>

using namespace std;

bool is_first(char c){
    switch (c){
        case 'a':
            break;
        case 'i':
            break;
        case 'o':
            break;
        case 'u':
            break;
        case 'e':
            break;
        case 'y':
            break;

        default:
            return false;   
    }

    return true;
}

int main(){
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    bool first = false, second = false;
    
    for(auto c : s){
        if(is_first(c)){
            first = true;
        }else{
            second = true;
        }

        if(first && second){
            first = second = false;
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}