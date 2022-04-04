#include <iostream>
#include <vector>

using namespace std;

const char zerop = '0';


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> sieve(n);

        // fill Fizz values
        for(int i = 2; i < n; i += 3)
            sieve[i] = "Fizz";
        
        // add Buzz values
        for(int i = 4; i < n; i += 5)
            sieve[i] += "Buzz";

        // fill empty values with numbers
        for(int i = 0; i < n; ++i)
            if(sieve[i].empty())
                sieve[i] = to_string(i + 1);

        return sieve;
    }
};


int main()
{
    int n;
    std::cin >> n;

    auto vec = Solution().fizzBuzz(n);

    for(int i = 0; i < n; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    return 0;
}
