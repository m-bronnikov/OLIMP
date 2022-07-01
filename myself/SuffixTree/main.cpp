#include <iostream>
#include <cstring>
#include <array>
#include <cassert>
#include "Alphabet.h"
#include "SuffixTree.h"


int main()
{
    custom::SuffixTree<> tree("hey");

    std::cout << custom::Alphabet<'a', 'b', 'c', 'g'>::size() << std::endl;
    auto arr = custom::Alphabet<'a', 'b', 'c', 'g'>::indices();

    constexpr custom::Alphabet<'a', 'b', 'c', 'g'> alphabet;

    std::cout << "idx: " << alphabet.index_of('c') << std::endl;
    std::cout << "alphabet of: " << alphabet.is_alphabet_of("abcggabcab") << std::endl;

    for(auto i : arr) 
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << custom::Alphabet<'a', 'b', 'c', 'g'>::is_exist('e') << std::endl;

    return 0;
}