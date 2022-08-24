#include <iostream>

class Solution {
private:
    static constexpr int genMask() {
        int mask = 0;
        for(int i = 1; i < 32; i += 2)
        {
            mask |= 1 << i;
        }
        return mask;
    }
    
public:
    bool isPowerOfFour(int n) {
        static constexpr int mask = genMask();
        return n > 0 && !((n & (n - 1)) | (n & mask));
    }
};

int main()
{
    std::cout << Solution().isPowerOfFour(16) << std::endl;
    return 0;
}