#include <iostream>

#define SOLUTION_2

#if defined(SOLUTION_1)

#include <vector>
#include <array>
#include <algorithm>
#include <cstring>

int char2int(char c) { return c - 'a'; }

using data_vector = std::vector<std::vector<std::string>>;

struct BorNode
{
    BorNode() { std::memset(parents.data(), -1, parents.size() * sizeof(int)); }

    int idx_of_leaf = -1;
    std::array<int, 26> parents{-1};
};

struct Bor
{
public:
    explicit Bor()
    {
        // alloc root node
        alloc_node();
    }


    int alloc_node()
    {
        nodes.push_back({});
        return nodes.size() - 1;
    }

    int jump_to_next(int current_node_idx, char c)
    {
        const int c2i = char2int(c);

        if(nodes[current_node_idx].parents[c2i] == -1){
            const int new_node_idx = alloc_node();
            nodes[current_node_idx].parents[c2i] = new_node_idx;
        }

        return nodes[current_node_idx].parents[c2i];
    }

    void add_to_leaf_of(int node_idx, std::string&& str)
    {
        BorNode& node = nodes[node_idx];
        if(node.idx_of_leaf == -1)
        {
            leaf_data.push_back({});
            node.idx_of_leaf = leaf_data.size() - 1;
        }

        leaf_data[node.idx_of_leaf].push_back(std::move(str));
    }

    void add_str(std::string&& str)
    {
        std::string sorted = str;
        std::sort(begin(sorted), end(sorted));

        int current_node_idx = root_idx;
        for(char c : sorted)
        {
            current_node_idx = jump_to_next(current_node_idx, c);
        }

        add_to_leaf_of(current_node_idx, std::move(str));
    }

    data_vector& access_leaf_data() { return leaf_data; }

private:
    static constexpr int root_idx = 0;

    std::vector<BorNode> nodes;
    data_vector leaf_data;
};


class Solution {
public:
    data_vector groupAnagrams(std::vector<std::string>& strs) {
        Bor bor;

        for(int i = 0; i < strs.size(); ++i)
        {
            bor.add_str(std::move(strs[i]));
        }

        data_vector data;
        data.swap(bor.access_leaf_data());

        return data;
    }
};

#elif defined(SOLUTION_2)

#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>

using data_vector = std::vector<std::vector<std::string>>;

class Solution {
public:
    data_vector groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> dict;

        std::string s;
        for(auto&& str : strs)
        {
            s = str;
            std::sort(begin(s), end(s));
            dict[s].push_back(std::move(str));
        }

        data_vector ans;
        ans.reserve(dict.size());

        for(auto&& [_, val] : dict)
        {
            ans.push_back(std::move(val));
        }

        return ans;
    }
};

#endif

int main()
{
    std::vector<std::string> data = {"eat","tea","tan","ate","nat","bat"};

    auto res = Solution().groupAnagrams(data);

    for(const auto& vec : res)
    {
        for(const auto& str : vec)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}