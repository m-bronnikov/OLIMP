#include <iostream>
using namespace std;

#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int j_is_z = 0;
        for(int j = 0; j < matrix.front().size(); ++j) {
            if(matrix.front()[j] == 0) {
                j_is_z = 1;
                break;
            }
        }

        int i_is_z = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            if(matrix[i].front() == 0) {
                i_is_z = 1;
            }

            for(int j = 1; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int j = 1; j < matrix.front().size(); ++j) {
            if(matrix.front()[j] != 0) {
                continue;
            }

            for(int i = 1; i < matrix.size(); ++i) {
                matrix[i][j] = 0;
            }
        }

        for(int i = 1; i < matrix.size(); ++i) {
            if(matrix[i].front() != 0) {
                continue;
            }

            for(int j = 1; j < matrix[i].size(); ++j) {
                matrix[i][j] = 0;
            }
        }

        if(i_is_z) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i].front() = 0;
            }
        }

        if(j_is_z) {
            for(int j = 0; j < matrix.front().size(); ++j) {
                matrix.front()[j] = 0;
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> m = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution().setZeroes(m);

    for(auto& l : m) {
        for(auto v : l) { 
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}