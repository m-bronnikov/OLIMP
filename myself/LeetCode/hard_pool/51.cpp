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

    vector<string> placed_to_space(const vector<int>& placed)
    {
        vector<string> space = vector<string>(placed.size(), string(placed.size(), '.'));
        for(int i = 0; i < placed.size(); ++i) {
            space[i][placed[i]] = 'Q';
        }

        return space;
    }

    void dfs_search(vector<int>& placed, vector<vector<string>>& res)
    {
        int n = placed.capacity();
        int i = placed.size();

        // if combination found: add to res
        if(i == n) {
            res.push_back(placed_to_space(placed));
            return;
        }

        // search
        for(int j = 0; j < n; ++j)
        {
            if(is_available(placed, j)){
                placed.push_back(j);
                dfs_search(placed, res);
                placed.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> placed;
        placed.reserve(n); // set capacity here to n

        vector<vector<string>> res;
        dfs_search(placed, res);

        return res;
    }
};


int main()
{
    auto res = Solution().solveNQueens(4);

    for(const auto& space : res)
    {
        std::cout << std::endl;

        for(const auto& line : space)
        {
            std::cout << line << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}