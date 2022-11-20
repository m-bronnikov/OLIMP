#include <iostream>
#include <limits>

uint64_t binsearch_upper_bound(uint64_t elem)
{
    uint64_t l = 0;
    uint64_t r = std::numeric_limits<uint32_t>::max();

    while(l < r)
    {
        uint64_t m = (l + r) >> 1;
        uint64_t cand = m * m;

        if(cand <= elem) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l - 1;
}

int main()
{
    std::ios::sync_with_stdio(false);

    uint64_t val;
    while(std::cin >> val)
    {
        static constexpr uint64_t limit_value = std::numeric_limits<uint32_t>::max() * static_cast<uint64_t>(std::numeric_limits<uint32_t>::max());
        if(val >=  limit_value)
        {
            std::cout << std::numeric_limits<uint32_t>::max() << std::endl;
            continue;
        }

        std::cout << binsearch_upper_bound(val) << std::endl;
    }


    return 0;
}
