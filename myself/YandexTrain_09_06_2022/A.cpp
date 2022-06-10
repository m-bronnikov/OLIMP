#include <iostream>
#include <string>
#include <vector>

int max(int a, int b) { return a > b ? a : b; }

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int find_digit(const std::string& str, int start = 0)
{
    do{
        if(is_digit(str[start]))
            return start;
    }while(++start);

    return 0;
}

int find_non_digit(const std::string& str, int start = 0)
{
    do{
        if(not is_digit(str[start]))
            return start;
    }while(++start);

    return 0;
}

int main()
{
    std::vector<std::string> strings;
    
    std::string str;
    while(std::getline(std::cin, str))
    {
        int start = find_digit(str);
        int end = find_non_digit(str, start);

        int idx = std::atoi(&str[start]);
        strings.resize(max(idx, strings.size()));

        str[start] = 0;
        str = std::string(&str[0]) + std::string(&str[end]);

        strings[idx - 1] = std::move(str);
    }

    for(const auto& str : strings)
    {
        std::cout << str << std::endl;
    }

    return 0;
}
