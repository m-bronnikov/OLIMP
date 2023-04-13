#include <iostream>

using namespace std;

#include <string_view>


class Solution {
private:
    inline static bool isSign(char c) 
    {
        return c == '+' || c == '-';
    }

    inline static bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    inline static bool isInteger(string_view s) 
    {
        if(isSign(s.front())) {
            s = s.substr(1);
        }

        if(s.size() == 0) {
            return false;
        }

        for(char c : s) {
            if(!isDigit(c)) {
                return false;
            }
        }

        return true;
    }

    inline static bool isDecimal(string_view s)
    {
        if(isSign(s.front())) {
            s = s.substr(1);
        }

        if(s.size() == 0) {
            return false;
        }

        int dots_count = 0;
        for(char c : s) {
            if(c == '.') {
                if(dots_count++) {
                    return false;
                }

                continue;
            }

            if(!isDigit(c)) {
                return false;
            }
        }

        return dots_count < s.size();
    }

public:
    bool isNumber(string_view s) {
        size_t find_e = s.size();
        for(size_t i = 0; i < s.size(); ++i) {
            if(s[i] == 'e' || s[i] == 'E') {
                find_e = i;
                break;
            }
        }

        if(find_e == s.size()) {
            return isDecimal(s);
        }

        return isDecimal(s.substr(0, find_e)) && isInteger(s.substr(find_e + 1));
    }
};


int main() {
    std::cout << Solution().isNumber(".e2342") << std::endl;

    return 0;
}