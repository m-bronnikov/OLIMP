// Made by Max Bronnikov
#include <string>
#include <iostream>

using namespace std;

using lli = long long int;

lli ceil(lli num, lli p){
    return (num + p - 1) / p;
}

bool inequality(lli num, lli p, lli q, lli r){
    return ceil(num, p) + ceil(num, q) + ceil(num, r) <= num;
}

// simple Euclid algo:
lli gcd(lli a, lli b){
    while(a){
        b %= a;
        std::swap(a, b);
    }
    return b;
}

lli nok(lli a, lli b){
    return a * b / gcd(a, b);
}

int main(){
    lli p, q, r, left, right;
    cin >> p >> q >> r >> left >> right;

    lli numerator = p*q + p*r + q*r;
    lli denumerator = p*q*r;

    if(numerator > denumerator){
        cout << 0 << endl;
        return 0;
    }
    if(numerator == denumerator){
        lli circle = nok(p, nok(q, r));
        lli answer = right - (ceil(left, circle) * circle);
        if(answer < 0){
            cout << 0 << endl;
        }else{
            answer = 1 + (answer / circle);
            cout << answer << endl;
        }
        return 0;
    }

    lli answer = right - left + 1;

    for(lli i = 1; i <= 4 * denumerator; ++i){
        if(i >= left && i <= right && not inequality(i, p, q, r)){
            --answer;
        }
    }

    cout << answer << endl;

    return 0;
}