#include <iostream>

#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    void define_minmax(TreeNode* node, int idx, int& min_idx, int& max_idx)
    {
        if(!node){
            return;
        }

        min_idx = idx < min_idx ? idx : min_idx;
        max_idx = idx > max_idx ? idx : max_idx;

        define_minmax(node->left, idx - 1, min_idx, max_idx);
        define_minmax(node->right, idx + 1, min_idx, max_idx);
    }

    struct Frame{
        int val = 0;
        int level = 0;

        static bool cmp(Frame lhs, Frame rhs){
            if(lhs.level == rhs.level){
                return lhs.val < rhs.val;
            }

            return lhs.level < rhs.level;
        }
    };

    void recursive_traversal(TreeNode* node, int lvl, int idx, std::vector<std::vector<Frame>>& cols)
    {
        if(!node)
        {
            return;
        }

        // add value
        cols[idx].push_back({node->val, lvl});

        // pass to next levels
        recursive_traversal(node->left, lvl + 1, idx - 1, cols);
        recursive_traversal(node->right, lvl + 1, idx + 1, cols);
    }

public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        int min_idx = 0;
        int max_idx = 0;
        define_minmax(root, 0, min_idx, max_idx);

        const int size = 1 + max_idx - min_idx;

        std::vector<std::vector<Frame>> frames(size);
        recursive_traversal(root, 0, -min_idx, frames);

        std::vector<std::vector<int>> cols(size);
        for(int i = 0; i < size; ++i)
        {
            std::sort(begin(frames[i]), end(frames[i]), Frame::cmp);

            cols[i].reserve(frames[i].size());
            for(Frame f : frames[i])
            {
                cols[i].push_back(f.val);
            }
        }
        
        return cols;
    }
};

int main()
{
    TreeNode node_2_0(4, nullptr, nullptr);
    TreeNode node_2_1(5, nullptr, nullptr);
    TreeNode node_2_2(6, nullptr, nullptr);
    TreeNode node_2_3(7, nullptr, nullptr);

    TreeNode node_1_0(2, &node_2_0, &node_2_1);
    TreeNode node_1_1(3, &node_2_2, &node_2_3);

    TreeNode node_0_0(1, &node_1_0, &node_1_1);

    auto const res = Solution().verticalTraversal(&node_0_0);
    for(const auto& col : res)
    {
        for(int i : col)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
