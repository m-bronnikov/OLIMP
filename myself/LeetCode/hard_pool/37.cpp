#include <iostream>

#include <vector>

using namespace std;

class Solution {
    bool check_is_valid(const vector<vector<char>>& space, int r, int c, char n)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(space[r][j] == n)
            {
                return false;
            }
        }

        for(int i = 0; i < 9; ++i)
        {
            if(space[i][c] == n)
            {
                return false;
            }
        }

        int start_i = 3 * (r / 3);
        int start_j = 3 * (c / 3);
        int end_i = start_i + 3;
        int end_j = start_j + 3;

        for(int i = start_i; i < end_i; ++i)
        {
            for(int j = start_j; j < end_j; ++j)
            {
                if(space[i][j] == n)
                {
                    return false;
                }
            }
        }

        return true;
    }


    bool dfs(vector<vector<char>>& space)
    {
        int i;
        int j;

        // find first empty ceil
        for(int idx = 0; idx < 81; ++idx)
        {
            i = idx / 9;
            j = idx - 9 * i;

            if(space[i][j] == '.')
            {
                break;
            }
        }

        if(space[i][j] != '.')
        {
            return true;
        }

        for(char n = '1'; n <= '9'; ++n)
        {
            if(!check_is_valid(space, i, j, n))
            {
                continue;
            }

            space[i][j] = n;
            
            if(dfs(space))
            {
                return true;
            }

            space[i][j] = '.';
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};

int main()
{
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution().solveSudoku(board);
    
    for(auto& line : board)
    {
        for(char ceil : line)
        {
            std::cout << ceil << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}