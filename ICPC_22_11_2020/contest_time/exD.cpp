// Made by Max Bronnikov
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef vector<string> simbol;

istream& operator>>(istream& is, simbol& new_char){
    for(auto& line : new_char){
        is >> line;
    }
    return is;
}

int compute_power(simbol& display){
    int max_power = 0;
    for(auto& line : display){
        char last = '.';
        int power = 0;
        for(char c : line){
            if(c == '#' && last == '.'){
                power += 2;
            }
            last = c;
        }
        max_power = power > max_power ? power : max_power;
    }
    return max_power;
}

int main(){
    int n, w, h, s;
    cin >> n >> w >> h >> s;

    simbol display(h);
    char max_c;
    int max_power = 0;

    for(int i = 0; i < n; ++i){
        char c;
        int power;

        cin >> c >> display;
        power = compute_power(display);

        if(power > max_power){
            max_power = power;
            max_c = c;
        }
        //cout << "Char: " << c << " Power: " << power << endl;
    }

    while(s > 0){
        cout << max_c;
        s -= max_power;
    }
    cout << endl;

    return 0;
}