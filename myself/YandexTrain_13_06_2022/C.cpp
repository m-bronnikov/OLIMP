#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int yandex = 0;
    int walet = 0;

    int price;
    std::cin >> price;

    for(int i = 1; i < n; ++i)
    {
        // future
        int next_price;
        std::cin >> next_price;

        if(next_price > price && !yandex)
        {
            yandex = 1;
            walet -= price;
        }

        if(next_price < price && yandex)
        {
            yandex = 0;
            walet += price;
        }

        price = next_price;
    }

    if(yandex)
    {
        walet += price;
    }

    std::cout << walet << std::endl;
}