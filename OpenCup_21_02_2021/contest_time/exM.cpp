#include <iostream>

using namespace std;


int main(){
    int a, b, c, d;
    cin >> a >> b  >> c >> d;

    while(a != 0 || b != 0 || c != 0 || d != 0){
        int step = 0;

        while(a != b || b != c || c != d){
            // compute new vals
            int aaa = abs(a - b);
            int bbb = abs(b - c);
            int ccc = abs(c - d);
            int ddd = abs(d - a);

            a = aaa;
            b = bbb;
            c = ccc;
            d = ddd;

            ++step;
        }

        cout << step << endl;

        cin >> a >> b  >> c >> d;
    }

    return 0;
}