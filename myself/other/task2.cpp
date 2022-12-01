#include <iostream>
#include <functional>

int min(int x, int y) { return x < y ? x : y; }

// uses idx2val instead array
int upper_bound_binsearch(std::function<int(int)> idx2val, int lim, int target)
{
    int l = 0;
    int r = lim;

    while(l < r)
    {
        int m = (l + r) >> 1;

        if(idx2val(m) <= target) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

int solution(int n, int m, int k)
{
    const auto min_required_jobs_for_value = [k, n](int x) -> int
    {
        // note k in range [1, n]
        int dl = min(x, k - 1);
        int dr = min(x, n - k);

        int loss = (dl * (dl + 1) + dr * (dr + 1)) >> 1;
        int gain = x * (dl + dr + 1);
        return gain - loss;
    };

    // each worker must have at least one job:
    m -= n;
    
    // find max possible value of jobs to dustrub remaining jobs
    return upper_bound_binsearch(min_required_jobs_for_value, m + 1, m);
}

int main()
{
    std::cout << solution(5, 11, 3) << std::endl;
    std::cout << solution(5, 11, 5) << std::endl;
    return 0;
}
