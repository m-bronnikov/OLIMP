#include <iostream>
using namespace std;

#include <vector>

class Solution {
private:
    bool is_available(const vector<int>& j_placed, int j_cand)
    {
        int i_cand = j_placed.size();
        for(int i = 0; i < i_cand; ++i)
        {
            if(j_placed[i] == j_cand) {
                return false;
            }

            if(abs(j_cand - j_placed[i]) == i_cand - i) {
                return false;
            }
        }

        return true;
    }

    int dfs_search(vector<int>& placed)
    {
        const int n = placed.capacity();
        const int i = placed.size();

        // if combination found: add to res
        if(i == n) {
            return 1;
        }

        // search
        int count = 0;
        for(int j = 0; j < n; ++j)
        {
            if(is_available(placed, j)){
                placed.push_back(j);
                count += dfs_search(placed);
                placed.pop_back();
            }
        }

        return count;
    }

public:
    int totalNQueens(int n) {
        vector<int> placed;
        placed.reserve(n); // set capacity here to n

        return dfs_search(placed);
    }
};


int main()
{
    for(int i = 1; i < 10; ++i)
    {
        std::cout << Solution().totalNQueens(i) << std::endl;
    }

    return 0;
}