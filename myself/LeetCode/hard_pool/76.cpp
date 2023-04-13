#include <iostream>
using namespace std;

#include <string>
#include <string_view>
#include <cstring>

class Solution {
private:
    static constexpr int chars_in_alpha = 26;
    static constexpr int chars_in_alpha_x2 = chars_in_alpha << 1;

    static int ch2int(char c) 
    {
        if('a' <= c && c <= 'z') {
            return c - 'a';
        }
        
        // else uppercase
        return c - 'A' + chars_in_alpha;
    }

public:
    string minWindow(const string_view s, const string_view t) {
        int chars_counts[chars_in_alpha_x2];
        memset(chars_counts, 0x00, chars_in_alpha_x2 * sizeof(int)); // set with 0

        int runtime_table[chars_in_alpha_x2];
        memset(runtime_table, 0x00, chars_in_alpha_x2 * sizeof(int)); // set with 0

        // count chars in t
        for(char c : t) {
            ++chars_counts[ch2int(c)];
        }

        int not_found = t.size();
        string_view min_substr = s;

        // substr interval: [l, r)
        int l = 0;
        int r = 0;

        auto go_right_till_valid = [&]() {
            while(r < s.size()) {
                // take char and go
                const char c = s[r++];
                const int chidx = ch2int(c);

                // skip redundant
                if(!chars_counts[chidx]) {
                    continue;
                }

                ++runtime_table[chidx];
                if(not_found && runtime_table[chidx] <= chars_counts[chidx]) {
                    --not_found;
                }

                // stop if found
                if(!not_found) {
                    break;
                }
            }
        };

        auto go_left_till_invalid = [&]() {
            while(l < r) {
                // take char and go
                const char c = s[l++];
                const int chidx = ch2int(c);

                // skip redundant
                if(!chars_counts[chidx]) {
                    continue;
                }

                --runtime_table[chidx];

                // if substr becomes invalid, go one char back and stop
                if(runtime_table[chidx] < chars_counts[chidx]) {
                    --l;
                    ++runtime_table[chidx];
                    break;
                }
            }
        };

        while(r < s.size()) {
            go_right_till_valid();
            go_left_till_invalid();

            if(r - l < min_substr.size()) {
                min_substr = s.substr(l, r - l);
            }
        }

        return not_found ? string() : string(min_substr);
    }
};


int main() {
    cout << Solution().minWindow("a", "aa") << endl;
    return 0;
}