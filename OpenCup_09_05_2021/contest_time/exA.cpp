// Made by Max Bronnikov
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct date{
    int day;
    int mounth;
};

bool operator<(date lhs, date rhs){
    if(lhs.mounth == rhs.mounth){
        return lhs.day < rhs.day;
    }

    return lhs.mounth < rhs.mounth;
}

int main(){
    map<date, string> calend = {
        {{19, 4}, "Aries"},
        {{20, 5}, "Taurus"},
        {{20, 6}, "Gemini"},
        {{22, 7}, "Cancer"},
        {{22, 8}, "Leo"},
        {{22, 9}, "Virgo"},
        {{22, 10}, "Libra"},
        {{22, 11}, "Scorpio"},
        {{21, 12}, "Sagittarius"},
        {{31, 12}, "Capricorn"},
        {{19, 1}, "Capricorn"},
        {{18, 2}, "Aquarius"},
        {{20, 3}, "Pisces"},
    };

    int day, mounth, year;

    cin >> year;
    cin.ignore(1);
    cin >> mounth;
    cin.ignore(1);
    cin >> day;
    cin.ignore(1);

    cout << calend.lower_bound({day, mounth})->second << endl;

    return 0;
}

