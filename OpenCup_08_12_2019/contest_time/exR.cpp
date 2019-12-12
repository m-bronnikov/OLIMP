#include <stdio.h>
#include <iostream>
#include <vector>

int main() {
    int n, p;
    std::string name, maxname;
    int c, max = 0;
    std::cin >> n;
    while (n) {
        std::cin >> p;
        for (int i = 0; i < p; ++i) {
            std::cin >> c >> name;
            if (i == 0) {
                max = c;
                maxname = name;
            } else {
                if (c > max) {
                    max = c;
                    maxname = name;
                }
            }
        }
        std::cout << maxname << std::endl;
        max = 0;
        --n;
    }
    return 0;
}