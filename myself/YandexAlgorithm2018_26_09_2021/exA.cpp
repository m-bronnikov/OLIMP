// Made by Maksim Bronnikov
#include <iostream>

using namespace std;

int main(){
    int hours, minuts;
    cin >> hours >> minuts;

    hours = (12 - hours) % 12;
    minuts = (60 - minuts) % 60;

    cout << hours << " " << minuts << endl;

    return 0;
}
