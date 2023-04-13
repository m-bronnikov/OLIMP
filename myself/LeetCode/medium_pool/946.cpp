#include <iostream>

#include <vector>
#include <algorithm>

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::reverse(begin(pushed), end(pushed));
        std::reverse(begin(popped), end(popped));

        std::vector<int> stack;

        while(!popped.empty())
        {
            if(stack.empty()) {
                stack.push_back(pushed.back());
                pushed.pop_back();
            }

            if(stack.back() == popped.back()) {
                stack.pop_back();
                popped.pop_back();
                continue;
            }

            if(pushed.empty()) {
                return false;
            }

            stack.push_back(pushed.back());
            pushed.pop_back();
        }   

        return true;     
    }
};


int main()
{
    std::vector<int> pushed = {1,2,3,4,5};
    std::vector<int> popped = {4,5,3,2,1};

    std::cout << Solution().validateStackSequences(pushed, popped) << std::endl;

    return 0;
}