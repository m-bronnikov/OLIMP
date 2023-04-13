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
    vector<vector<int>> subsets(const vector<int>& nums) {
        std::vector<vector<int>> ans;

        int reserve = 1;
        for(int k = 1; k <= ans.size(); ++k) {
            reserve += Cnk(ans.size(), k);
        }
        ans.reserve(reserve);

        ans.push_back({});

        std::vector<int> tpl;
        std::vector<int> sub;
        tpl.reserve(nums.size());
        sub.reserve(nums.size());

        for(int k = 1; k <= nums.size(); ++k) {
            tpl.resize(k);
            sub.resize(k);
            for(int i = 0; i < k; ++i) {
                tpl[i] = k - i - 1;
                sub[i] = nums[tpl[i]];
            }

            while(true) {
                ans.push_back(sub);

                int wi = 0;
                while(wi < k) {
                    if(++tpl[wi] < nums.size() - wi) {
                        sub[wi] = nums[tpl[wi]];
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
                    sub[wi] = nums[tpl[wi]];
                }
            }
        }

        return ans;
    }
};


int main() 
{
    auto vec = Solution().subsets({1, 2, 3});

    std::cout << "<" << vec.size() << ">" << std::endl;
    for(auto& comb : vec) {
        for(int v : comb) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}