#include <iostream>
#include <vector>

int main()
{
    uint32_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<uint64_t> char_to_time(256, 0);

    char max_ch = 0;
    uint64_t max_ch_time = 0;

    uint32_t last_time = 0;
    for(auto c : s)
    {
        uint32_t time;
        std::cin >> time;

        char_to_time[c] += time - last_time;

        if(char_to_time[c] >= max_ch_time)
        {
            max_ch_time = char_to_time[c];
            max_ch = c;

        }

        last_time = time;
    }


    std::cout << static_cast<char>(max_ch) << std::endl;

    return 0;
}