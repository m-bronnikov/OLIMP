#include <iostream>
#include <vector>
#include <algorithm>

static constexpr int max_n = 40;

void recoursive_search(int min_val, int target, std::vector<int>& candidat, std::vector<std::vector<int>>& ans)
{
    if(target == 0)
    {
        ans.push_back(candidat);
        std::reverse(begin(ans.back()), end(ans.back()));
    }

    for(int i = min_val; i <= target; ++i)
    {
        candidat.push_back(i);
        recoursive_search(i, target - i, candidat, ans);
        candidat.pop_back();
    }
}


int main()
{
    std::vector<int> candidat;
    candidat.reserve(max_n);

    int target;
    std::cin >> target;

    std::vector<std::vector<int>> ans;
    recoursive_search(1, target, candidat, ans);

    auto const cmp = [](const std::vector<int>& l, const std::vector<int>& r)
    {
        int min_size = l.size() > r.size() ? r.size() : l.size();
        for(int i = 0; i < min_size; ++i)
        {
            if(l[i] < r[i])
            {
                return true;
            }
            if(l[i] > r[i])
            {
                return false;
            }
        }

        return l.size() < r.size();
    };
    std::sort(begin(ans), end(ans), cmp);

    for(const auto& line : ans)
    {
        for(int v : line)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
