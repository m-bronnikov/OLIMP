// Made by Maksim Zhyvikh
#include <iostream>
#include <string>

using namespace std;


int main() {
    string str;
    cin >> str;

    int vowels = 0, consonants = 0;

    for (int i = 0; i < str.length(); ++i) {
        switch (str[i]) {
        case 'a':
            vowels++;
            break;
        case 'e':
            vowels++;
            break;
        case 'i':
            vowels++;
            break;
        case 'o':
            vowels++;
            break;
        case 'u':
            vowels++;
            break;
        case 'y':
            break;
        default:
            consonants++;
            break;
        }
    }

    int res = 0;

    while (!(vowels > consonants)) {
        vowels++;
        consonants--;
        res++;
    }

    cout << res << endl;

    return 0;
}