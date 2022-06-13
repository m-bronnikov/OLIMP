#include <iostream>
#include <algorithm>
#include <string>

#define to_idx(c) (c - 'a')

static constexpr int alphabet_size = 26;

// note data in .text segment of executable is zero initailized automatically
static int substr_counter[alphabet_size];
static int str_counter[alphabet_size];

bool check_counters()
{
    int total_diff = 0;
    for(int i = 0; i < alphabet_size; ++i)
    {
        int diff = substr_counter[i] - str_counter[i];
        diff = diff < 0 ? -diff : diff;
        total_diff += diff;
    }

    return total_diff == 2;
}

int main()
{
    std::string s;    
    std::string t;

    std::cin >> t >> s;

    if(t.size() < s.size()){
        std::cout << -1 << std::endl;
        return 0;
    }

    const int str_size = s.size();

    for(int i = 0; i < str_size; ++i)
    {
        str_counter[to_idx(s[i])]++;
        substr_counter[to_idx(t[i])]++;
    }

    // check case of first substr
    if(check_counters())
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    for(int substr_start = 0; substr_start + str_size < t.size(); ++substr_start){
        // update counter
        --substr_counter[to_idx(t[substr_start])];
        ++substr_counter[to_idx(t[substr_start + str_size])];

        if(check_counters())
        {
            std::cout << substr_start + 1 << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}
