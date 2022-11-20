#include <iostream>
#include <deque>


int main()
{
    std::ios::sync_with_stdio(false);

    std::deque<int> passangers;

    while(true)
    {
        int code;
        std::cin >> code;
        
        switch (code)
        {
            case 1:
            {
                int city;
                std::cin >> city;
                passangers.push_front(city);
                break;
            }
            case 2:
            {
                int city;
                std::cin >> city;
                passangers.push_back(city);
                break;
            }
            case 3:
            {
                int city = passangers.front();
                passangers.pop_front();
                std::cout << city << std::endl;
                break;
            }
            case 4:
            {
                int city = passangers.back();
                passangers.pop_back();
                std::cout << city << std::endl;
                break;
            }
            case 5:
            {
                int city = passangers.front();
                std::cout << city << std::endl;  
                break;
            }
            case 6:
            {
                int city = passangers.back();
                std::cout << city << std::endl;  
                break;
            }
            case 7:
            {
                std::cout << passangers.size() << std::endl;
                break;
            }
            case 8:
            {
                passangers.clear();
                break;
            }
            case 9:
            default:
                return 0;
        }
    }

    return 0;
}