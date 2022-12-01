#include <iostream>
#include <iomanip>

int main()
{
    constexpr int sec_per_min = 60;
    constexpr int sec_per_hour = 60 * sec_per_min;

    int time;
    std::cin >> time;

    int hour = time / sec_per_hour;
    int min = (time  - hour * sec_per_hour) / sec_per_min;
    int secs = time - hour * sec_per_hour - min * sec_per_min;


    std::cout << std::setfill('0') << std::setw(2) << hour;
    std::cout << ":";
    std::cout << std::setfill('0') << std::setw(2) << min;
    std::cout << ":";
    std::cout << std::setfill('0') << std::setw(2) << secs;
    std::cout << std::endl;

    return 0;
}