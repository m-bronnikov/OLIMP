#include <iostream>

#include <vector>

class Solution {
private:
    using Segment = std::vector<int>;

    static size_t upper_bound_search(const std::vector<Segment>& segs, size_t l, size_t r, int v) {
        while(l < r) {
            size_t m = (l + r) >> 1;

            if(v >= segs[m].front()) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }

    static void move_segs(std::vector<Segment>& segs, size_t src, size_t dst, size_t count) {
        if(src == dst) {
            return;
        }

        if(src > dst) {
            while(count--) {
                segs[dst++] = std::move(segs[src++]);
            }
        } else {
            dst += count;
            src += count;
            while(count--) {
                segs[--dst] = std::move(segs[--src]);
            }
        }
    }
    
public:
    std::vector<std::vector<int>> insert(std::vector<Segment>& intervals, Segment& new_interval) {
        size_t intervals_size = intervals.size();

        size_t l = upper_bound_search(intervals, 0, intervals_size, new_interval.front());
        size_t r = upper_bound_search(intervals, l, intervals_size, new_interval.back());

        if(l > 0 && new_interval.front() <= intervals[l - 1].back()) {
            --l;
            new_interval.front() = intervals[l].front();
        }

        if(r > 0 && new_interval.back() <= intervals[r - 1].back()) {
            new_interval.back() = intervals[r - 1].back();
        }

        const size_t overlapping_intervals = r - l;
        if(!overlapping_intervals) {
            intervals.push_back({});
        }

        move_segs(intervals, r, l + 1, intervals_size - r);
        intervals[l] = std::move(new_interval);
        intervals.resize(intervals_size - overlapping_intervals + 1);

        return intervals;
    }
};


int main()
{
    std::vector<std::vector<int>> segs = {{2,5},{6,7},{8,9}};
    std::vector<int> interval = {0, 1};

    auto ans = Solution().insert(segs, interval);

    for(auto seg : segs) {
        std::cout << seg.front() << " " << seg.back() << std::endl;
    }

    return 0;
}