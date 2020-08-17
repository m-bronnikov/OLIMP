#include <iostream>
#include <map>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    cout << a << endl;
    cout << b << endl;
    
    if(a.size() != b.size()){
        cout << "0" << endl;
        return 0;
    }

    map<char, char> c;

    for(int i = 0; i < a.size(); ++i){
        if(c.find(a[i]) == c.end()){
            c[a[i]] = b[i];
            continue;
        }

        if(c[a[i]] != b[i]){
            cout << "0" << endl;
            return 0;
        }
    }

    cout << "1" << endl;
    return 0;
}