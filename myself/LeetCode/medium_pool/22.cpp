#include <iostream>

#include <string>
#include <array>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::string tpl;
        tpl.reserve(n << 1);

        std::vector<std::string> result;
        result.reserve(katalan_numbers[n]);

        tpl.push_back('(');
        addRecursivelly(result, tpl, 1, n - 1);
        return result;
    }

private:
    void addRecursivelly(std::vector<std::string>& result, std::string& tpl, int opened, int to_open)
    {
        if(!to_open && !opened)
        {
            result.push_back(tpl);
            return;
        }

        // if to open exist => open another
        if(to_open)
        {
            tpl.push_back('(');
            addRecursivelly(result, tpl, opened + 1, to_open - 1);
            tpl.pop_back();
        }

        // if opened exist => close another
        if(opened)
        {
            tpl.push_back(')');
            addRecursivelly(result, tpl, opened - 1, to_open);
            tpl.pop_back();
        }
    }

    // first 9 katalan numbers
    static constexpr std::array<int, 9> katalan_numbers = {1, 1, 2, 5, 14, 42, 132, 429, 1430};
};


int main()
{
    const auto res = Solution().generateParenthesis(5);
    for(const auto& str : res)
    {
        std::cout << str << std::endl;
    }

    return 0;
}