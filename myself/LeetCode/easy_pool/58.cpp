#include <iostream>

#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {        
        while(s.back() == ' ')
        {
            s.pop_back();
        }
        
        int count = 0;
        while(!s.empty() && s.back() != ' ')
        {
            s.pop_back();
            ++count;
        }

        return count;
    }
};

int main()
{
    std::cout << Solution().lengthOfLastWord("World") << std::endl;

    return 0;
}