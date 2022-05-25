#include <string>
#include <iostream>

#include <array>

class Solution {
public:
    std::string convert(const std::string& s, int num_rows) {
        // zig zag conversion do nothing in this case
        if(num_rows == 1)
            return s;

        std::string ans;
        ans.reserve(s.size());

        for(int r = 0; r < num_rows; ++r)
        {
            int descent_step = (num_rows - r - 1) << 1;
            int ascent_step = r << 1;

            // for borders is no matter descent or ascent, but step equal to 0 is incorrect
            descent_step = descent_step ? descent_step : ascent_step;
            ascent_step = ascent_step ? ascent_step : descent_step;

            const std::array<int, 2> step_by_mode = {descent_step, ascent_step};

            for(int mode = 0, i = r; i < s.size(); i += step_by_mode[mode], mode ^= 1)
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};


int main()
{
    std::cout << Solution().convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << Solution().convert("PAYPALISHIRING", 4) << std::endl;

    return 0;
}