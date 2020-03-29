// Made by Lina Veltman

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int sum = 0;
    std::vector<unsigned int> numbers(6);
    for (int i = 0; i < numbers.size(); ++i) {
        std::cin >> numbers[i];
        sum += numbers[i];
    }
    std::vector<unsigned int>::iterator max = std::max_element(numbers.begin(), numbers.end());
    std::vector<unsigned int>::iterator min = std::min_element(numbers.begin(), numbers.end());
    
    sum -= (*max + *min);
    if (!(sum & 1) && (sum / 2) == (*max + *min)) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
       