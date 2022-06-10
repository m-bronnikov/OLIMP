#include <iostream>

int main()
{
    uint64_t H, W;
    std::cin >> H >> W;

    uint64_t row_sum = 0;
    for(uint64_t i = 0; i < W; ++i)
    {
        row_sum += (W - i) * (i + 1);
    }

    uint64_t column_sum = 0;
    for(uint64_t j = 0; j < H; ++j)
    {
        column_sum += (H - j) * (j + 1);
    }

    for(uint64_t i = 0; i < W; ++i)
    {
        std::cout << column_sum * (W - i) * (i + 1) << ' ';
    }
    std::cout << std::endl;
    for(uint64_t j = 0; j < H; ++j)
    {
         std::cout << row_sum * (H - j) * (j + 1) << ' ';
    }
    std::cout << std::endl;

    return 0;
}
