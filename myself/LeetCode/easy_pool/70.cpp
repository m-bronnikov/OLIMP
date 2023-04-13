#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int last = 1;
        int prelast = 1;
        
        for(int i = n - 2; i >= 0; --i) {
            int cur = last + prelast;
            prelast = last;
            last = cur;
        }

        return last;
    }
};


int main() {
    std::cout << Solution().climbStairs(3) << std::endl;
    return 0;
}