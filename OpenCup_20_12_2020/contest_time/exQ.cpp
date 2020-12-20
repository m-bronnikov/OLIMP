// Made by Max Bronnikov
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    long long dist, speed1, speed2;

    cin >> dist >> speed1 >> speed2;
    while(dist | speed1 | speed2){

        long long secs1, secs2;

        secs1 = round((double)(dist * 3600) / ((double)speed1) - (double)(dist * 3600) / ((double)speed2));

        secs1 -= secs2;

        secs1 = secs1 < 0 ? -secs1 : secs1;

        long long  hours1 = secs1 / 3600;
        secs1 -= hours1 * 3600;

        long long mins1 = secs1 / 60;
        secs1 -= mins1 * 60; 



        cout << hours1 << ":";
        cout << std::setfill('0') << std::setw(2) << mins1 << ":";
        cout << std::setfill('0') << std::setw(2) << secs1 << endl;


        cin >> dist >> speed1 >> speed2;
    }
    return 0;
}