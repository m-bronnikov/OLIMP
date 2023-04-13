#include <iostream>

using namespace std;

#include <string>
#include <vector>

class Solution {
private:
    // [l, r)
    static string complete_line(vector<string>& words, int l, int r, int words_sum, int width) {
        int words_count = r - l;
        int delims_count = words_count - 1;

        if(delims_count == 0) {
            string line = std::move(words[l]);
            line.resize(width, ' ');
            return line;
        }

        int spaces = width - words_sum;
        int min_space_add = spaces / delims_count;
        int mod_space_add = spaces - min_space_add * delims_count;

        std::string line = std::move(words[l]);
        line.reserve(width);

        for(int i = l + 1; i < r; ++i) {
            line.resize(line.size() + min_space_add, ' ');
            if(mod_space_add) {
                line.push_back(' ');
                --mod_space_add;
            }

            line += std::move(words[i]);
        }

        return line;
    }

    // [l, r)
    static string complete_last_line(vector<string>& words, int l, int r, int words_sum, int width) {
        int words_count = r - l;
        int spaces = width - words_sum;

        std::string line = std::move(words[l]);
        line.reserve(width);

        for(int i = l + 1; i < r; ++i) {
            line.push_back(' ');
            line += std::move(words[i]);
        }

        line.resize(width, ' ');
        return line;
    }

public:
    vector<string> fullJustify(vector<string>& words, int width) {
        int lines_complete = 0;

        int l = 0;
        int r = 0;
        int min_len = 0;

        while(r < words.size()) {
            int next_len = min_len + words[r].size() + r - l;
            if(width < next_len) {
                words[lines_complete++] = complete_line(words, l, r, min_len, width);

                // start new segment
                l = r;
                min_len = 0;
            }

            min_len += words[r++].size();
        }

        words[lines_complete++] = complete_last_line(words, l, r, min_len, width);
        words.resize(lines_complete);

        return words;
    }
};

int main() 
{
    std::vector<std::string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    
    auto ans = Solution().fullJustify(words, 20);

    for(auto& line : ans) {
        std::cout << line.size() << " ";
        std::cout << line << std::endl;
    }
    
    return 0;
}