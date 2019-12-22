#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>



int main() {
    int k, n;
    std::cin >> k;
    std::vector<int> v(50000, 0);
    std::vector<int> dp(50000, 0);
    while (k) {
        std::cin >> n;
        for (int j = 0; j < n; ++j) {
            std::cin >> v[j];
        }
        dp[0] = v[0];
        dp[1] = std::max(v[0], v[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = std::max(dp[i-2]+v[i], dp[i-1]);
        }
        
        std::cout << dp[n-1] << std::endl;
        --k;
    }
    return 0;
}