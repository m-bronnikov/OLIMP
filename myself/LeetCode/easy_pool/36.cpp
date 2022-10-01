#include <iostream>

#include <vector>
#include <array>

using namespace std;

class Solution {
private:
    static bool check_columns(const vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; ++i)
        {
            std::array<int, 10> arr{0};

            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }

                if(arr[board[i][j] - '0'])
                {
                    return false;
                }

                arr[board[i][j] - '0'] = 1;
            }
        }

        return true;
    }


    static bool check_rows(const vector<vector<char>>& board)
    {
        for(int j = 0; j < 9; ++j)
        {
            std::array<int, 10> arr{0};

            for(int i = 0; i < 9; ++i)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }

                if(arr[board[i][j] - '0'])
                {
                    return false;
                }

                arr[board[i][j] - '0'] = 1;
            }
        }

        return true;
    }

    static bool check_quads(const vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                std::array<int, 10> arr{0};
                
                for(int k = i; k < i + 3; ++k)
                {
                    for(int m = j; m < j + 3; ++m)
                    {
                        if(board[k][m] == '.')
                        {
                            continue;
                        }

                        if(arr[board[k][m] - '0'])
                        {
                            return false;
                        }

                        arr[board[k][m] - '0'] = 1;
                    }
                }
            }
        }

        return true;
    }


public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        bool ans = check_columns(board);

        if(ans)
        {
            ans = check_rows(board);
        }

        if(ans)
        {
            ans = check_quads(board);
        }

        return ans;
    }
};

int main()
{
    std::vector<std::vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    std::cout << Solution().isValidSudoku(board) << std::endl;

    return 0;
}