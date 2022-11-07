#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>
#include <string_view>


// pass to eliminate '*' with other stars in a row
void merge_clini_stars(std::string& pattern)
{
    if(pattern.empty())
    {
        return;
    }

    int j = 0;
    for(int i = 1; i < pattern.size(); ++i)
    {
        if(pattern[i] == '*' && pattern[j] == '*')
        {
            continue;
        }

        pattern[++j] = pattern[i];
    }
    pattern.resize(j + 1);
}

struct Solver{
public:
    Solver() = default;
    bool match(const std::string_view str, const std::string_view pat)
    {
        memo.assign((str.size() + 1) * pat.size(), 0);
        return match_internal(0, 0, str, pat);
    }

private:
    bool match_internal(uint32_t str_pos, uint32_t pat_pos, const std::string_view str, const std::string_view pat)
    {
        if(str_pos == str.size() && pat_pos == pat.size())
        {
            return true;
        }

        if(str_pos > str.size() || pat_pos == pat.size())
        {
            return false;
        }

        const uint32_t key = str_pos * pat.size() + pat_pos;
        if(memo[key]) {
            return false;
        }

        const char str_c = str[str_pos];
        const char pat_c = pat[pat_pos];

        if(pat_c == '*')
        {
            if(match_internal(str_pos + 1, pat_pos + 1, str, pat))
            {
                return true;
            }

            if(match_internal(str_pos + 1, pat_pos, str, pat))
            {
                return true;
            }

            if(match_internal(str_pos, pat_pos + 1, str, pat))
            {
                return true;
            }
            
            memo[key] = 1;
            return false;
        }
        
        if(str_c == pat_c || pat_c == '?')
        {
            if(match_internal(str_pos + 1, pat_pos + 1, str, pat))
            {
                return true;
            }
        }

        memo[key] = 1;
        return false;
    }

private:
    std::vector<uint8_t> memo;
};


class Solution {
public:
    bool isMatch(const std::string& str, std::string& pat) {
        // 1. optimize symbols
        merge_clini_stars(pat);

        // 2. match patterm
        return Solver().match(str, pat);
    }
};


int main()
{
    //std::string a = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    //std::string b = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    
    std::string a = "a";
    std::string b = "a*";

    std::cout << Solution().isMatch(a, b) << std::endl;
    return 0;
}
