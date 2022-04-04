#include <vector>
#include <iostream>

using namespace std;


using matrix = vector<vector<int>>;

class Solution {
public:
    vector<int> kWeakestRows(matrix& mat, int k) {
        int n = mat.size();
        int m = mat.front().size();

        // preallocate all required data as single vector and separate it to 3 arrays
        std::vector<int> data(k + n + m + 1, 0);
        int* weakest = data.data();
        int* power = weakest + k;
        int* counter = power + n;

        // compute values for each row and count power values
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                power[i] += mat[i][j];
            }

            ++counter[power[i]];
        }

        // inclusive scan of hystogram
        ++m;
        for(int j = 1; j < m; ++j)
        {
            counter[j] += counter[j - 1];
        }

        // prealloc answer, but needs resize later

        // sort rows as count sort (but store only indices)
        for(int i = n - 1; i >= 0; --i)
        {
            int pow = power[i];
            if(--counter[pow] < k)
                weakest[counter[pow]] = i;
        }

        data.resize(k);
        return data;   
    }
};


int main()
{
    int k = 3;
    matrix mat = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
    };

    auto ans = Solution().kWeakestRows(mat, k);
    
    for(auto idx : ans)
        std::cout << idx << " ";
    std::cout << std::endl;


    return 0;
}