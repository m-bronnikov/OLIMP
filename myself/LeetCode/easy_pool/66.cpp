#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        for(int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += add;

            if(digits[i] != 10) {
                add = 0;
                break;
            }

            digits[i] = 0;
        }

        if(add) {
            digits.push_back(0);
            digits.front() = 1;
        }

        return digits;
    }
};

int main() {
    // this task withput test
    return 0;
}