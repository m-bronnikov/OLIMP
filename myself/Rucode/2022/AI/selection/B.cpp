#include <iostream>

#include <vector>
#include <string>

class Solver{
public:
    Solver(const std::vector<std::string>& _space) : space(_space)
    {}

    int result(const char* target)
    {
        int count = 0;

        for(int i = 0; i < space.size(); ++i)
        {
            for(int j = 0; j < space.front().size(); ++j)
            {
                if(space[i][j] == target[0])
                {
                    count += recursion(i, j, target + 1);
                }
            }
        }

        return count;
    }

private:
    int recursion(int i, int j, const char* target)
    {
        // check the end
        if(*target == '\0')
        {
            return 1;
        }

        // main routine
        int count = 0;
        if(space[i][j - 1] == *target)
        {
            count += recursion(i, j - 1, target + 1);
        }

        if(space[i][j + 1] == *target)
        {
            count += recursion(i, j + 1, target + 1);
        }

        if(space[i + 1][j] == *target)
        {
            count += recursion(i + 1, j, target + 1);
        }

        return count;
    }

private:
    const std::vector<std::string>& space;
};


int main()
{
    const std::vector<std::string> space = {
        "xxxxxkxxxxx",
        "xxxxklkxxxx",
        "xxxklilkxxx",
        "xxklikilkxx",
        "xklikakilkx",
        "xxxxxxxxxxx"
    };
    const char* target = "klika";

    auto solver = Solver(space);
    std::cout << solver.result(target) << std::endl; // answer is 31

    return 0;
}