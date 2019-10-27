// Made by Bronnikov Max
#include <iostream>
#include <string>

using namespace std;

int main(){
    unsigned Total, Res = 0;
    short unsigned p, pricePos = 0;
    string str;
    getline(cin, str, '\n');
    while(str != "TOTAL"){
        cin >> pricePos >> p;
        Res += p*pricePos;
        cin.clear();
        fflush(stdin);
        getline(cin, str, '\n');
    }
    cin >> Total;
    if(Total > Res){
        cout << "PROTEST" << endl;
    }else{
        cout << "PAY" << endl;
    }
    return 0;
}
