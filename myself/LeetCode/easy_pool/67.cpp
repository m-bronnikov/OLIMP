#include <iostream>

using namespace std;

#include <string>
#include <algorithm>

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));

        if(a.size() < b.size()) {
            a.swap(b);
        }
        
        int add = 0;
        for(int i = 0; i < b.size(); ++i) {
            a[i] += b[i] - '0' + add;
            add = 0;
            if(a[i] > '1') {
                a[i] -= 2;
                add = 1;
            }
        }

        for(int i = b.size(); i < a.size(); ++i) {
            a[i] += add;
            add = 0;
            if(a[i] > '1') {
                a[i] -= 2;
                add = 1;
            }
        }

        if(add){
            a.push_back('1');
        }

        reverse(begin(a), end(a));
        return a;
    }
};

int main() {
    std::cout << Solution().addBinary("111", "01") << std::endl;
    return 0;
}
