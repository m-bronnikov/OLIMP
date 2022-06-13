#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
    int zeros_count = 0;
    int positive_count = 0;

    int overall_sign = 1;

    int min_power = std::numeric_limits<int>::max();
    int min_pos_power = std::numeric_limits<int>::max();
    int max_neg_power = std::numeric_limits<int>::min();

    int count = 0;
    std::cin >> count;

    for(auto i = 0; i < count; ++i)
    {
        int power;
        std::cin >> power;

        min_power = std::min(min_power, power);

        if(power > 0)
        {
            min_pos_power = std::min(min_pos_power, power);
            ++positive_count;
        }
        else if(power == 0){
            ++zeros_count;
        }
        else{
            max_neg_power = std::max(max_neg_power, power);
            overall_sign *= -1;
        }
    }


    // first case: more than 1 zeros
    if(zeros_count > 1)
    {
        // return any
        std::cout << 0 << std::endl;
        return 0;
    }

    // second case: 1 zero
    if(zeros_count == 1)
    {
        // if sign is positive: return zero
        if(overall_sign > 0)
        {
            std::cout << 0 << std::endl;
            return 0;
        }
        
        // else return any except 0, let it be minimal element (guaranteed less than 0)
        std::cout << min_power << std::endl;
        return 0;
    }

    // third(default) case: 0 zeros
    if(overall_sign > 0)
    {
        if(positive_count)
        {
            std::cout << min_pos_power << std::endl;
            return 0;
        }
        
        // all powers are negative: return minimal
        std::cout << min_power << std::endl;
    }
    else{
        std::cout << max_neg_power << std::endl;
    }

    return 0;
}