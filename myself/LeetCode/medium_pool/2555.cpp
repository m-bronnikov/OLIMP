#include <iostream>

#include <vector>

class Solution
{
private:
    static int max(int a, int b) { return a > b ? a : b; }

public:
    int maximizeWin(std::vector<int>& arr, int k)
    {
        // slide window over prizes positions to define coverage
        for(int i = 0, j = 1; i < arr.size(); ++i)
        {
            while(j < arr.size() && arr[j] - arr[i] <= k)
            {
                ++j;
            }

            arr[i] = j - i;
        }

        arr.push_back(0);

        int max_score = 0;
        int last_add = 0;
        
        for(int i = arr.size() - 1, j = i; i >= 0; --i)
        {
            while(i + arr[i] < j)
            {
                --j;
                arr[j] = max(arr[j], arr[j + 1]);
            }

            last_add = max(last_add, arr[i + arr[i]]);
            max_score = max(max_score, arr[i] + last_add);
        }

        return max_score;
    }
};

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 9, 10, 11, 12};
    std::cout << Solution().maximizeWin(arr, 5) << std::endl;;
    return 0;
}