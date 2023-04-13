#include <iostream>
using namespace std;

#include <vector>

class Solution {
private:
    static int Cnk(int n, int k) {
        k = min(k, n - k);

        int numenator = 1;
        int denumenator = 1;

        for(int i = 1; i <= k; ++i) {
            numenator *= n - k + i;
            denumenator *= i;
        }

        return numenator / denumenator;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<vector<int>> ans;
        ans.reserve(Cnk(n, k));

        std::vector<int> tpl(k);
        for(int i = 0; i < k; ++i) {
            tpl[i] = k - i;
        }

        while(true) {
            ans.push_back(tpl);

            int wi = 0;
            while(wi < k) {
                if(++tpl[wi] <= n - wi) {
                    break;
                }
                ++wi;
            }

            if(wi == k) {
                break;
            }

            while(wi > 0) {
                tpl[wi - 1] = tpl[wi] + 1;
                --wi;
            }
        }


        return ans;
    }
};


int main() 
{
    auto vec = Solution().combine(6, 3);

    std::cout << "<" << vec.size() << ">" << std::endl;
    for(auto& comb : vec) {
        for(int v : comb) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}