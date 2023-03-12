#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution {
private:
    static int max(int lhs, int rhs) { return lhs > rhs ? lhs : rhs; }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto const cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            if(lhs.front() == rhs.front()) {
                return lhs.back() < rhs.back();
            }

            return lhs.front() < rhs.front();
        };

        sort(begin(intervals), end(intervals), cmp);
        
        int i = 0;
        for(int j = 1; j < intervals.size(); ++j) {
            if(intervals[i].back() >= intervals[j].front()) {
                // merge
                intervals[i].back() = max(intervals[i].back(), intervals[j].back());
                continue;
            }

            intervals[++i].swap(intervals[j]);
        }
        intervals.resize(i + 1);

        std::cout << intervals.size() << std::endl;

        return std::move(intervals);
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 4}, {5, 6}};
    auto res = Solution().merge(vec);

    for(auto& pair : res) {
        std::cout << pair.front() << " " << pair.back() << std::endl;
    }

    return 0;
}