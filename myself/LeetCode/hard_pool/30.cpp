#include <iostream>

#include <array>
#include <vector>
#include <string>
#include <string_view>
#include <cstring>

using namespace std;

int char_to_idx(char c) { return c - 'a'; }

struct BorNode
{
    BorNode()
    {
        memset(next.data(), 0xFF, next.size() * sizeof(int));
    }

    int count = 0;
    array<int, 26> next;
};

struct Bor
{
    Bor() : nodes(1, BorNode()) {}

    void add_string(string_view str)
    {
        int node_id = root_id;
        
        for(const char c : str)
        {
            int next_node_id = nodes[node_id].next[char_to_idx(c)];

            if(next_node_id != -1)
            {
                node_id = next_node_id;
                continue;
            }
            
            next_node_id = nodes.size();
            nodes.push_back(BorNode());

            nodes[node_id].next[char_to_idx(c)] = next_node_id;
            node_id = next_node_id;
        }

        nodes[node_id].count++;
    }

    int search_string(string_view str) const
    {
        int node_id = root_id;
        
        for(const char c : str)
        {
            node_id = nodes[node_id].next[char_to_idx(c)];
            
            if(node_id == -1)
            {
                break;
            }
        }

        return node_id;
    }

    static constexpr int root_id = 0;
    vector<BorNode> nodes;
};


class Solution {
public:
    vector<int> findSubstring(const string& s, const vector<string>& words) 
    {
        vector<int> result;

        Bor bor;
        for(auto const& w : words)
        {
            bor.add_string(w);
        }

        const int word_size = words.front().size();
        const int border = static_cast<int>(s.size()) - static_cast<int>(words.size() * word_size);
        
        // memoization of bor's nodes for already found words
        vector<int> dp(s.size(), 0);
        for(int i = 0; i <= border; ++i)
        {
            // search words in this position
            vector<int> found;
            found.reserve(words.size());
            
            for(int j = i; found.size() < words.size(); j += word_size)
            {
                if(!dp[j])
                {
                    dp[j] = bor.search_string(string_view(&s[j], word_size));
                }
                int node_id = dp[j];

                if(node_id == -1)
                {
                    break;
                }

                if(bor.nodes[node_id].count == 0)
                {
                    break;
                }

                bor.nodes[node_id].count--;
                found.push_back(node_id);
            }

            if(found.size() == words.size())
            {
                result.push_back(i);
            }

            for(int node_id : found)
            {
                bor.nodes[node_id].count++;
            }
        }

        return result;
    }
};

int main()
{
    auto result = Solution().findSubstring("barfoofoobarthefoobarman", {"foo","bar", "the"});

    for(int i : result)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}