#include <stdio.h>
#include <iostream>

// Q parallel computing
int main() {
    int t, d, n, s, p;
    std::cin >> t;
    while (t) {
            std::cin >> d >> n >> s >> p;
            if ((d + p*n) > (n*s)) {
                std::cout << "do not parallelize" << std::endl;
            }
            else if ((d + p*n) < (n*s)) {
                std::cout << "parallelize" << std::endl;
            }
            else {
                std::cout << "does not matter" << std::endl;
            }
        --t;
    }
    return 0;
}