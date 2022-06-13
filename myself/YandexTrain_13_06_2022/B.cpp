#include <string>
#include <iostream>
#include <set>

int main()
{
    std::set<std::string> vocab;
    
    int n;
    std::cin >> n;

    while(n--)
    {
        std::string s;
        std::cin >> s;

        int j = 0;
        int i = 0;

        bool skip_all = false;

        for(; s[i] != '@'; ++i)
        {
            if(s[i] == '-') skip_all = true;

            if(skip_all) continue;

            if(s[i] == '.') continue;

            s[j++] = s[i];
        }

        // add @ simbol
        s[j++] = s[i++];

        int last_point = -1;
        for(; i < s.size(); ++i)
        {
            if(s[i] == '.') last_point = j;

            s[j++] = s[i];
        }

        s.resize(last_point);
        vocab.insert(std::move(s));
    }

    std::cout << vocab.size() << std::endl;

    return 0;
}