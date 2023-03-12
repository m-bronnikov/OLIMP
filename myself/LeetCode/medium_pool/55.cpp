#include <iostream>
using namespace std;

#include <vector>

class Solution {
private:
    static int max(int a, int b) { return a > b ? a : b; }
public:
    bool canJump(const vector<int>& nums) {
        int available_jump = 1;
        for(int i = 0; i < nums.size() - 1; ++i) {
            available_jump = max(available_jump - 1, nums[i]);
            if(available_jump == 0) {
                return false;
            }
        }

        return true;
    }
};


int main()
{
    std::cout << Solution().canJump({2,3,1,1,4}) << std::endl; 

    return 0;
}