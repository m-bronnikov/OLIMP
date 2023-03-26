#include <iostream>

#include <string>
#include <cstring>
#include <array>

class Solution {
private:
    static int get_factorial(int n) {
        int res = 1;
        while(n) {
            res *= n--;
        }

        return res;
    }

public:
    std::string getPermutation(int n, int k) {
        --k; // make 0-indexed

        // init array of used indexes
        std::array<uint8_t, 10> is_used;
        std::memset(is_used.data(), 0, is_used.size());

        auto find_idx = [&is_used](int idx) {
            // search val by idx
            for(int i = 0; true; ++i) {
                if(is_used[i]) {
                    continue;
                }

                if(idx) {
                    --idx;
                    continue;
                }

                is_used[i] = 1; // mark as busy
                return i;
            }

            return -1; // error here
        };

        std::string permut;
        permut.reserve(n);

        int fact = get_factorial(n);
        while(n) {
            fact /= (n--); // update fact

            int idx = k / fact; // div
            k -= idx * fact; // modulo
            
            int find = find_idx(idx);
            permut.push_back('1' + find);
        }

        return permut;
    }
};


int main()
{
    std::cout << Solution().getPermutation(4, 9) << std::endl;
    return 0;
}