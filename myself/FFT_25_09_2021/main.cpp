// Made by Maksim Bronnikov
#include <iostream>
#include <vector>

#include "complex.h"
#include "fft.h"

using namespace std;

uint32_t upper_pow_of_two(uint32_t num)
{
    --num;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    return num + 1;
}

int main(){
    std::vector<custom::complex> data = { 
        {1.0, 0}, {1.0, 0}, {1.0, 0}, {1.0, 0}, 
        {0.0, 0}, {0.0, 0}, {0.0, 0}, {0.0, 0}, 
        {1.0, 0}, {1.0, 0}, {1.0, 0}, {1.0, 0}, 
        {0.0, 0}, {0.0, 0}, {0.0, 0}, {0.0, 0} 
    };
    
    std::cout << "Input:" << std::endl;
    for(auto const &in : data){
        std::cout << in << std::endl;
    }
    std::cout << std::endl;

    inplace_fft(data, /*inverse=*/ false);
    std::cout << "Ouput:" << std::endl;
    for(auto const &out : data){
        std::cout << out << ", ";
    }
    std::cout << std::endl;

    inplace_fft(data, /*inverse=*/ true);
    std::cout << "Inverse:" << std::endl;
    for(auto const &rev : data){
        std::cout << rev << std::endl;
    }
    std::cout << std::endl;

    return 0;
}