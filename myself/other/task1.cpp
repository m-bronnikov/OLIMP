#include <iostream>

#include <algorithm>
#include <vector>

int getMaximumRewardPoints(int k, const std::vector<int>& a, const std::vector<int>& b)
{
    const int size = a.size();

    std::vector<int> indexes(size);
    for(int i = 0; i < size; ++i)
    {
        indexes[i] = i;
    }

    const auto cmp = [&a, &b](int lhs, int rhs) { return (a[lhs] - b[lhs]) > (a[rhs] - b[rhs]); };
    std::nth_element(begin(indexes), begin(indexes) + k, end(indexes), cmp);

    int score = 0;
    for(int i = 0; i < k; ++i)
    {
        score += a[indexes[i]];
    }
    for(int i = k; i < size; ++i)
    {
        score += b[indexes[i]];
    }

    return score;
}

int main()
{
    std::cout << getMaximumRewardPoints(3, {1, 2, 3, 2}, {1, 2, 3, 2}) << std::endl;
    std::cout << getMaximumRewardPoints(3, {2, 3, 4, 1}, {1, 1, 1, 1}) << std::endl;

    return 0;
}
