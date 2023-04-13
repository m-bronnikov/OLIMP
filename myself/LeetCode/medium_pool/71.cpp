#include <iostream>

using namespace std;

#include <string>
#include <vector>
#include <string_view>

class Solution {
public:
    string simplifyPath(string path) {
        std::vector<string_view> stack;

        string_view rest = path;
        while(!rest.empty()) {
            size_t next_slash = rest.find('/');
            string_view token = rest.substr(0, next_slash);

            rest = (next_slash == rest.npos) ? "" : rest.substr(next_slash + 1);

            if(token.empty() || token == ".") {
                continue;
            }

            if(token == "..") {
                if(!stack.empty()) {
                    stack.pop_back();
                }
                continue;
            }

            stack.push_back(token);
        }

        if(stack.empty()) {
            return "/";
        }

        string new_path;
        for(string_view dir : stack) {
            new_path += "/";
            new_path += dir;
        }

        return new_path;
    }
};


int main()
{
    std::cout << Solution().simplifyPath("/a//b////c/d//././/..") << std::endl;
    return 0;
}