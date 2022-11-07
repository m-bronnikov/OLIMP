#include <iostream>

#include <vector>


class Solution {
private:
    int chr2int(char c) const { return c - '0'; }

public:
    bool haveConflict(const std::vector<std::string>& event1, const std::vector<std::string>& event2) {
        int e1_start_h = chr2int(event1.front()[0]) * 10 + chr2int(event1.front()[1]);
        int e2_start_h = chr2int(event2.front()[0]) * 10 + chr2int(event2.front()[1]);

        int e1_start_m = chr2int(event1.front()[3]) * 10 + chr2int(event1.front()[4]);
        int e2_start_m = chr2int(event2.front()[3]) * 10 + chr2int(event2.front()[4]);

        int e1_end_h = chr2int(event1.back()[0]) * 10 + chr2int(event1.back()[1]);
        int e2_end_h = chr2int(event2.back()[0]) * 10 + chr2int(event2.back()[1]);

        int e1_end_m = chr2int(event1.back()[3]) * 10 + chr2int(event1.back()[4]);
        int e2_end_m = chr2int(event2.back()[3]) * 10 + chr2int(event2.back()[4]);

        int e1_start = e1_start_h * 100 + e1_start_m;
        int e2_start = e2_start_h * 100 + e2_start_m;

        int e1_end = e1_end_h * 100 + e1_end_m;
        int e2_end = e2_end_h * 100 + e2_end_m;

        //std::cout << e1_start << " " << e1_end << " " << e2_start << " " << e2_end << std::endl;

        if(e1_start <= e1_end && e1_end < e2_start && e2_start <= e2_end)
        {
            return false;
        }

        if(e2_start <= e2_end && e2_end < e1_start && e1_start <= e1_end)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    std::cout << Solution().haveConflict({"01:15", "02:00"}, {"02:00", "03:00"}) << std::endl;
    return 0;
}