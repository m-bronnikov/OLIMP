#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>



int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    
    int answer = array[0], left = 0, right = 0;
    int sum = 0, min_sum = 0, min_pos = -1;
    
    for (int i = 0; i < n; ++i) {
        sum += array[i];
     
        int cur = sum - min_sum;
        if (cur > answer) {
            answer = cur;
            left = min_pos + 1;
            right = i;
        }
     
        if (sum < min_sum) {
            min_sum = sum;
            min_pos = i;
        }
    }
    
    std::cout << left + 1 << " " << right + 1 << std::endl;
    return 0;
}