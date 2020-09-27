#include <iostream>

using namespace std;

int main(){
    size_t T;
    cin >> T;
    for(size_t t = 0; t < T; ++t){
        int p, q, a, b;
        cin >> p >> q >> a >> b;
        int numinator, denuminator, n;
        numinator = 100 * b * (q - p);
        denuminator = a*p*b*(100 - q) - q*(100 - p);
        // cout << "denum: " << denuminator << endl;
        if(denuminator <= 0){
            cout << "-1" << endl;
            continue;
        }
        n = numinator / denuminator;
        
        n += (numinator > denuminator * n) ? 1 : 0;
        cout << n << endl;
    }

    return 0;
}