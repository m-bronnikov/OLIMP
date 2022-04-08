#include <vector>
#include <iostream>

#include <set>

using namespace std;


struct greater_cmp
{
    bool operator()(int lhs, int rhs) const
    {
        return rhs < lhs;
    }
};

class Solution {
public:
    int lastStoneWeight(const vector<int>& stones) {
        std::multiset<int, greater_cmp> sorted_stones(begin(stones), end(stones));

        while(sorted_stones.size() > 1)
        {
            int fisrt = *(sorted_stones.cbegin());
            sorted_stones.erase(sorted_stones.cbegin());

            int second = *(sorted_stones.cbegin());
            sorted_stones.erase(sorted_stones.cbegin());

            int diff = fisrt - second;
            if(diff)
            {
                sorted_stones.insert(diff);
            }
        }

        return sorted_stones.empty() ? 0 : *(sorted_stones.begin());
    }
};


int main()
{
    std::cout << Solution().lastStoneWeight({2, 2}) << std::endl;
    return 0;
}
