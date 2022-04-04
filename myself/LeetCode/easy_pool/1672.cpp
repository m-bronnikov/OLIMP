#include <iostream>
#include <vector>

using namespace std;


using grid = vector<vector<int>>;

class Solution {
public:
    int maximumWealth(grid& accounts) {
        int max = 0;

        for(auto &person : accounts)
        {
            int wealth = 0;
            for(auto bank : person)
            {
                wealth += bank;
            }

            max = wealth > max ? wealth : max;
        }

        return max;
    }
};


int main()
{
    grid accounts = {{1,2,3}, {3,2,1}};
    std::cout << Solution().maximumWealth(accounts) << std::endl;
    return 0;
}