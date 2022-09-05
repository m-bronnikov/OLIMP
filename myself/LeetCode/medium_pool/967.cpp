#include <iostream>

#include <vector>

class Solution {
private:
    static inline int concat(int to, int from) { return 10*to + from; }

    void recoursive_search(int num, int acc, int k, int n)
    {
        acc = concat(acc, num);

        if(--n == 0)
        {
            result.push_back(acc);
            return;
        }

        if(num + k < 10){
            recoursive_search(num + k, acc, k, n);
        }

        if(num - k >= 0){
            recoursive_search(num - k, acc, k, n);
        }
    }

    void zero_k_case(int num, int n)
    {
        int acc = 0;

        for(int j = 0; j < n; ++j)
        {
            acc = concat(acc, num);
        }

        result.push_back(acc);
    }

public:
    std::vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i < 10; ++i)
        {
            if(k == 0)
            {
                zero_k_case(i, n);
                continue;
            }

            recoursive_search(i, 0, k, n);
        }

        std::vector<int> ans = std::move(result);
        return ans;
    }

private:
    std::vector<int> result;
};


int main()
{
    auto ans = Solution().numsSameConsecDiff(2, 0);
    for(int n : ans)
    {
        std::cout << n << std::endl;
    }

    return 0;
}