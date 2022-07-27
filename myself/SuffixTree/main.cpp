#include <iostream>
#include <cstring>
#include <array>
#include <cassert>
#include "Alphabet.h"
#include "SuffixTree.h"


/**
 * @brief Some common alphabet.
 */
using EnglishLowercaseLetters = custom::SuffixTreeAlphabet<
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
>;


int main()
{
    static constexpr std::string_view str("fhgkbfkgbskfgbkfhbghfhgghgghhghghggggggggggghhghhghghhhhghghhghghghghhg");
    static constexpr std::string_view pattern("fhgkbfkgbskfgbkfhbghfhgghgghhghghggggggggggghhghhghg");

    custom::SuffixTree<EnglishLowercaseLetters> tree(str);
    std::cout << (tree.contains(pattern) ? "contains" : "not contains") << std::endl;

    std::cout << custom::Alphabet<'a', 'b', 'c', 'g'>::size() << std::endl;
    auto arr = custom::Alphabet<'a', 'b', 'c', 'g'>::indices();

    static constexpr custom::Alphabet<'a', 'b', 'c', 'g'> alphabet;

    std::cout << "idx: " << alphabet.index_of('c') << std::endl;
    std::cout << "alphabet of: " << alphabet.is_alphabet_of("abccg") << std::endl;

    for(auto i : arr) 
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << custom::Alphabet<'a', 'b', 'c', 'g'>::is_exist('e') << std::endl;

    return 0;
}