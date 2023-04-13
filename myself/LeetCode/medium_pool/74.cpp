#include <iostream>
using namespace std;

#include <vector>

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix.front().size();
        int size = n * m;

        auto const at = [&matrix, m](int idx) -> int {
            int i = idx / m;
            int j = idx - i * m;
            return matrix[i][j];
        };

        // start linear binsearch
        int l = 0;
        int r = size - 1;
        while(l < r) {
            int m = (l + r) >> 1;
            int el = at(m);

            if(el == target) {
                return true;
            }

            if(el < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return at(l) == target;
    }
};

int main() {
    std::vector<std::vector<int>> m = {{0,3,5,7},{10,11,16,20},{23,30,34,60}};
    std::cout << Solution().searchMatrix(m, 3) << std::endl;
    
    return 0;
}