#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(unsigned x) {
        if(x < 2) {
            return x;
        }

        unsigned l = 2;
        unsigned r = 1 << 16;

        while(l < r) {
            unsigned m = (l + r) >> 1;
            unsigned m2 = m * m;

            if(m2 <= x) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l - 1;
    }
};

int main() {
    std::cout << Solution().mySqrt(14334) << std::endl;
    return 0;
}