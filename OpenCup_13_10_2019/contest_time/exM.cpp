
#include <iostream>
#include <algorithm>
#include <vector>

struct bludo {
    int p;
    int w;
};

bool comparator(const bludo &a, const bludo &b) {
    return a.p < b.p;
}


int main(int argc, const char * argv[]) {
    int n, s;
    std::cin >> n;
    std::vector<bludo> g(n);
    std::cin >> s;
    int p, w;
    int summ = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> p >> w;
        g[i].p = p;
        g[i].w = w;
    }
    std::sort(g.begin(), g.end(), comparator);

    for (int i = n - 1; i >= 0; --i) {
        if (s > g[i].w) {
            summ += g[i].p * g[i].w;
            s -= g[i].w;
        }
        else {
            summ += s * g[i].p;
            break;
        }
    }
    std::cout << summ;
    return 0;
}