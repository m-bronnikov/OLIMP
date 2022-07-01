#include <iostream>
#include <cstring>
#include <array>
#include <cassert>
#include "Alphabet.h"


int main()
{
    std::cout << custom::Alphabet<'a', 'b', 'c', 'g'>::size() << std::endl;
    auto arr = custom::Alphabet<'a', 'b', 'c', 'g'>::indices();

    for(auto i : arr) 
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << custom::Alphabet<'a', 'b', 'c', 'g'>::is_exist('e') << std::endl;

    return 0;
}