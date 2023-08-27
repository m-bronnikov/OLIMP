#include <iostream>

#include <vector>
#include <utility>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) 
    {
        int max_area = 0;

        auto update_max_area = [&max_area](int from, int to, int height) {
            const int area = (to - from) * height;
            max_area = (area > max_area) ? area : max_area;
        };

        // start positions of rectangles (sorted by height)
        std::vector<int> start_positons;

        for (int i = 0; i < heights.size(); ++i) {
            int merged_start = i;

            // merge all rectangles finished at this point (with heigths larger than current) and update max area by them
            while(!start_positons.empty() && heights[start_positons.back()] >= heights[i]) {
                const int start = start_positons.back();
                start_positons.pop_back();

                merged_start = merged_start < start ? merged_start : start;
                update_max_area(start, i, heights[start]);
            }

            // add new merged rectangle to stack and update `heights` vector since we not store heigths in stack
            heights[merged_start] = heights[i];
            start_positons.push_back(merged_start);
        }

        // all rest rectangles finished at this point
        while(!start_positons.empty()) {
            const int start = start_positons.back();
            start_positons.pop_back();

            update_max_area(start, heights.size(), heights[start]);
        }

        return max_area;
    }
};


int main() 
{
    std::vector<int> h = {2,1,5,6,2,3};
    std::cout << Solution().largestRectangleArea(h) << std::endl;
    return 0;
}