#include <iostream>
#include <vector>

using namespace std;

const long long lim = 25;

int main(){
    int N;
    cin >> N;
    vector<long long> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    while(N--){
        long long c;
        cin >> c;
        if(c > lim){
            cout << "no" << endl;
            continue;
        }

        int flag = 1;
        for(long long i = 1; i < lim; ++i){
            long long j = c - i;
            long long abc = c * i * j;
            long long rad = 1;
            for(int k = 0; rad*primes[k] < abc; ++k){
                rad *= primes[k];
            }
            if(rad < abc){
                cout << "yes" << endl;
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << "no" << endl;
        }
    }

    return 0;
}