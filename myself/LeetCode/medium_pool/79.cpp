#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <string_view>


class Solution {
private:
    static bool search(int i, int j, vector<vector<char>>& board, string_view rest) {
        const char c = rest.front();
        if(c != board[i][j]) {
            return false;
        }
        
        rest = rest.substr(1);
        if(rest.empty()) {
            return true;
        }

        // mark as visited
        board[i][j] = 0;
        
        if(j + 1 < board[i].size() && search(i, j + 1, board, rest)) {
            return true;
        }

        if(i + 1 < board.size() && search(i + 1, j, board, rest)) {
            return true;
        }

        if(j > 0 && search(i, j - 1, board, rest)) {
            return true;
        }

        if(i > 0 && search(i - 1, j, board, rest)) {
            return true;
        }

        // unmark visited
        board[i][j] = c;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string_view word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(search(i, j, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() 
{
    vector<vector<char>> space1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> space2 = {{'A'}};

    std::cout << Solution().exist(space2, "A") << std::endl;

    return 0;
}